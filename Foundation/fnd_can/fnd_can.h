/*
 * fnd_can.h
 *
 *  Created on: 2022Äê8ÔÂ2ÈÕ
 *      Author: Litao
 */

#ifndef FOUNDATION_FND_CAN_FND_CAN_H_
#define FOUNDATION_FND_CAN_FND_CAN_H_

#include "Ifx_Types.h"
#include "IfxCan_Can.h"
#include "can.h"

typedef struct
{
    IfxCan_Can_Config canConfig;         /* CAN module configuration structure                   */
    IfxCan_Can canModule;                /* CAN module handle                                    */
    IfxCan_Can_Node canNode;             /* CAN source node handle data structure                */
    IfxCan_Can_NodeConfig canNodeConfig; /* CAN node configuration structure                     */
    IfxCan_Filter canFilter;             /* CAN filter configuration structure                   */
    IfxCan_Message txMsg;                /* Transmitted CAN message structure                    */
    IfxCan_Message rxMsg;                /* Received CAN message structure                       */
    uint32 txData[2];                    /* Transmitted CAN data array                           */
    uint32 rxData[2];                    /* Received CAN data array                              */
} McmcanType;

void fnd_can_init(void);

unsigned char canSend(CAN_PORT notused, Message *msg);

#endif /* FOUNDATION_FND_CAN_FND_CAN_H_ */
