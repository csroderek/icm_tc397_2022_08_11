/*
 * fnd_can.c
 *
 *  Created on: 2022Äê8ÔÂ2ÈÕ
 *      Author: Litao
 */

#include "fnd_can.h"
#include "FreeRTOS.h"
#include "task.h"
#include "ObjDict.h"

#define MODULE_CAN0_RAM 0xF0200000
#define MODULE_CAN1_RAM 0xF0210000
#define MODULE_CAN2_RAM 0xF0220000
#define NODE0_RAM_OFFSET 0x0
#define NODE1_RAM_OFFSET 0x1000
#define NODE2_RAM_OFFSET 0x2000
#define NODE3_RAM_OFFSET 0x3000

#define ISR_PRIORITY_CAN_TX 60 /* Define the CAN TX interrupt priority                 */
#define ISR_PRIORITY_CAN_RX 61 /* Define the CAN RX interrupt priority                 */

IFX_INTERRUPT(canIsrTxHandler, 1, ISR_PRIORITY_CAN_TX);
IFX_INTERRUPT(canIsrRxHandler, 1, ISR_PRIORITY_CAN_RX);

McmcanType g_mcmcan;

IFX_CONST IfxCan_Can_Pins Can1_node0_pins = {
    &IfxCan_TXD10_P00_0_OUT, IfxPort_OutputMode_pushPull, // CAN00_TX
    &IfxCan_RXD10A_P00_1_IN, IfxPort_InputMode_pullUp,    // CAN00_RX
    IfxPort_PadDriver_cmosAutomotiveSpeed4};

IFX_CONST IfxCan_Can_Pins Can1_node1_pins = {
    &IfxCan_TXD11_P02_5_OUT, IfxPort_OutputMode_pushPull, // CAN00_TX
    &IfxCan_RXD11A_P02_4_IN, IfxPort_InputMode_pullUp,    // CAN00_RX
    IfxPort_PadDriver_cmosAutomotiveSpeed4};

IFX_CONST IfxCan_Can_Pins Can2_node0_pins = {
    &IfxCan_TXD20_P10_7_OUT, IfxPort_OutputMode_pushPull, // CAN00_TX
    &IfxCan_RXD20F_P11_14_IN, IfxPort_InputMode_pullUp,   // CAN00_RX
    IfxPort_PadDriver_cmosAutomotiveSpeed4};

uint32_t can_trans_cnt = 0;
uint32_t can_rec_cnt = 0;

void canIsrTxHandler(void)
{
    can_trans_cnt++;
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canNode.node, IfxCan_Interrupt_transmissionCompleted);
}

void canIsrRxHandler(void)
{
    can_rec_cnt++;
    IfxCan_Node_clearInterruptFlag(g_mcmcan.canNode.node, IfxCan_Interrupt_rxFifo0NewMessage);
    g_mcmcan.rxMsg.readFromRxFifo0 = TRUE;
    IfxCan_Can_readMessage(&g_mcmcan.canNode, &g_mcmcan.rxMsg, g_mcmcan.rxData);

    Message msg;
    msg.cob_id = g_mcmcan.rxMsg.messageId;
    msg.len = g_mcmcan.rxMsg.dataLengthCode;
    msg.rtr = g_mcmcan.rxMsg.remoteTransmitRequest;
    for (uint8_t i = 0; i < msg.len; i++)
    {
        if (i < 4)
        {
            msg.data[i] = (uint8_t)(g_mcmcan.rxData[0] >> (8 * i));
        }
        else
        {
            msg.data[i] = (uint8_t)(g_mcmcan.rxData[1] >> (8 * (i - 4)));
        }
    }
    canDispatch(&ObjDict_Data, &msg);
}

void fnd_can_init(void)
{
    IfxCan_Can_Config canConfig;
    IfxCan_Can_initModuleConfig(&canConfig, &MODULE_CAN1);
    IfxCan_Can_initModule(&g_mcmcan.canModule, &canConfig);

    IfxCan_Can_NodeConfig nodeConfig;
    IfxCan_Can_initNodeConfig(&nodeConfig, &g_mcmcan.canModule);

    nodeConfig.nodeId = IfxCan_NodeId_0;
    nodeConfig.frame.type = IfxCan_FrameType_transmitAndReceive;
    nodeConfig.baudRate.baudrate = 500000;

    // nodeConfig.txConfig.txMode = IfxCan_TxMode_dedicatedBuffers;
    nodeConfig.txConfig.txMode = IfxCan_TxMode_fifo;
    nodeConfig.txConfig.txBufferDataFieldSize = IfxCan_DataFieldSize_8;
    nodeConfig.txConfig.txFifoQueueSize = 32;

    nodeConfig.rxConfig.rxMode = IfxCan_RxMode_fifo0;
    nodeConfig.rxConfig.rxFifo0DataFieldSize = IfxCan_DataFieldSize_8;
    nodeConfig.rxConfig.rxFifo0Size = 16;

    nodeConfig.messageRAM.baseAddress = MODULE_CAN1_RAM + NODE0_RAM_OFFSET;
    nodeConfig.pins = &Can1_node0_pins;

    nodeConfig.filterConfig.messageIdLength = IfxCan_MessageIdLength_standard;
    nodeConfig.filterConfig.standardListSize = 1;
    nodeConfig.filterConfig.standardFilterForNonMatchingFrames = IfxCan_NonMatchingFrame_reject;

    nodeConfig.interruptConfig.transmissionCompletedEnabled = TRUE;
    nodeConfig.interruptConfig.traco.priority = ISR_PRIORITY_CAN_TX;
    nodeConfig.interruptConfig.traco.interruptLine = IfxCan_InterruptLine_0;
    nodeConfig.interruptConfig.traco.typeOfService = IfxSrc_Tos_cpu1;

    nodeConfig.interruptConfig.rxFifo0NewMessageEnabled = TRUE;
    nodeConfig.interruptConfig.rxf0n.priority = ISR_PRIORITY_CAN_RX;
    nodeConfig.interruptConfig.rxf0n.interruptLine = IfxCan_InterruptLine_1;
    nodeConfig.interruptConfig.rxf0n.typeOfService = IfxSrc_Tos_cpu1;

    IfxCan_Can_initNode(&g_mcmcan.canNode, &nodeConfig);

    IfxCan_Filter filter;
    filter.number = 0;
    filter.type = IfxCan_FilterType_range;
    filter.elementConfiguration = IfxCan_FilterElementConfiguration_storeInRxFifo0;
    filter.id1 = 0x000;
    filter.id2 = 0xFFF;
    filter.rxBufferOffset = (IfxCan_RxBufferId)0;
    IfxCan_Can_setStandardFilter(&g_mcmcan.canNode, &filter);
}

void transmitCanMessage(void)
{
    static uint32_t low_word = 0;
    static uint32_t high_word = 0;
    IfxCan_Can_initMessage(&g_mcmcan.txMsg);

    g_mcmcan.txData[0] = low_word++;
    g_mcmcan.txData[1] = high_word++;
    g_mcmcan.txMsg.messageId = 0x666;

    while (IfxCan_Status_notSentBusy ==
           IfxCan_Can_sendMessage(&g_mcmcan.canNode, &g_mcmcan.txMsg, &g_mcmcan.txData[0]))
    {
        ;
    }
}

uint32 can_error_cnt = 0;

unsigned char canSend(CAN_PORT notused, Message *msg)
{
    uint8_t result = 0;

    IfxCan_Message tx_msg;
    IfxCan_Can_initMessage(&tx_msg);
    tx_msg.messageId = msg->cob_id;
    tx_msg.remoteTransmitRequest = msg->rtr;
    tx_msg.dataLengthCode = msg->len;

    g_mcmcan.txData[0] = (((uint32_t)msg->data[3]) << 24) + (((uint32_t)msg->data[2]) << 16) + (((uint32_t)msg->data[1]) << 8) + msg->data[0];
    g_mcmcan.txData[1] = (((uint32_t)msg->data[7]) << 24) + (((uint32_t)msg->data[6]) << 16) + (((uint32_t)msg->data[5]) << 8) + msg->data[4];

    result = IfxCan_Can_sendMessage(&g_mcmcan.canNode, &tx_msg, &g_mcmcan.txData[0]) == IfxCan_Status_ok ? 0 : 1;
    if (result == 1)
    {
        can_error_cnt++;
    }
    return result;
}
