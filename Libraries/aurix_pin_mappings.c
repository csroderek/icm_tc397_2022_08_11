/*
 * Generated by TASKING Pin Mapper for AURIX
 * - device  : TC39XEDB
 * - package : LFBGA292
 */

#include "aurix_pin_mappings.h"


/* GPIO pin configuration */

static const IfxPort_Io_ConfigPin gpio_pin_table[] = 
{
    IFXCFG_P14_0_IO_CONFIG,
    IFXCFG_P14_6_IO_CONFIG,
    IFXCFG_P14_9_IO_CONFIG,
    IFXCFG_P15_0_IO_CONFIG,
    IFXCFG_P15_1_IO_CONFIG,
    IFXCFG_P15_2_IO_CONFIG,
    IFXCFG_P15_3_IO_CONFIG,
    IFXCFG_P15_4_IO_CONFIG,
    IFXCFG_P15_5_IO_CONFIG,
    IFXCFG_P20_9_IO_CONFIG,
    IFXCFG_P22_1_IO_CONFIG,
    IFXCFG_P22_3_IO_CONFIG,
    IFXCFG_P22_5_IO_CONFIG,
    IFXCFG_P22_10_IO_CONFIG,
    IFXCFG_P22_11_IO_CONFIG,
    IFXCFG_P23_1_IO_CONFIG,
    IFXCFG_P23_2_IO_CONFIG,
    IFXCFG_P23_3_IO_CONFIG,
    IFXCFG_P23_4_IO_CONFIG,
    IFXCFG_P23_5_IO_CONFIG,
    IFXCFG_P23_6_IO_CONFIG,
    IFXCFG_P23_7_IO_CONFIG,
    IFXCFG_P32_2_IO_CONFIG,
    IFXCFG_P32_3_IO_CONFIG,
    IFXCFG_P33_4_IO_CONFIG,
    IFXCFG_P33_6_IO_CONFIG,
    IFXCFG_P33_10_IO_CONFIG,
    IFXCFG_P33_11_IO_CONFIG,
    IFXCFG_P33_12_IO_CONFIG,
    IFXCFG_P33_13_IO_CONFIG,
    IFXCFG_P33_14_IO_CONFIG,
    IFXCFG_P33_15_IO_CONFIG
};

static const IfxPort_Io_Config gpio_io_config_table = 
{
    sizeof(gpio_pin_table)/sizeof(IfxPort_Io_ConfigPin),
    (IfxPort_Io_ConfigPin*)gpio_pin_table
};

extern void gpio_init_pins(void)
{
    IfxPort_Io_initModule(&gpio_io_config_table);
}


/* QSPI1_M pin configuration */

static const IfxPort_Io_ConfigPin qspi1_m_pin_table[] = 
{
    IFXCFG_P10_1_IO_CONFIG,
    IFXCFG_P10_2_IO_CONFIG,
    IFXCFG_P10_3_IO_CONFIG,
    IFXCFG_P10_4_IO_CONFIG
};

static const IfxPort_Io_Config qspi1_m_io_config_table = 
{
    sizeof(qspi1_m_pin_table)/sizeof(IfxPort_Io_ConfigPin),
    (IfxPort_Io_ConfigPin*)qspi1_m_pin_table
};

extern void qspi1_m_init_pins(void)
{
    IfxPort_Io_initModule(&qspi1_m_io_config_table);
}


/* QSPI3_M pin configuration */

static const IfxPort_Io_ConfigPin qspi3_m_pin_table[] = 
{
    IFXCFG_P01_4_IO_CONFIG,
    IFXCFG_P01_5_IO_CONFIG,
    IFXCFG_P01_6_IO_CONFIG,
    IFXCFG_P01_7_IO_CONFIG
};

static const IfxPort_Io_Config qspi3_m_io_config_table = 
{
    sizeof(qspi3_m_pin_table)/sizeof(IfxPort_Io_ConfigPin),
    (IfxPort_Io_ConfigPin*)qspi3_m_pin_table
};

extern void qspi3_m_init_pins(void)
{
    IfxPort_Io_initModule(&qspi3_m_io_config_table);
}


/* TOUT11 pin configuration */

static const IfxPort_Io_ConfigPin tout11_pin_table[] = 
{
    IFXCFG_P00_2_IO_CONFIG
};

static const IfxPort_Io_Config tout11_io_config_table = 
{
    sizeof(tout11_pin_table)/sizeof(IfxPort_Io_ConfigPin),
    (IfxPort_Io_ConfigPin*)tout11_pin_table
};

extern void tout11_init_pins(void)
{
    IfxPort_Io_initModule(&tout11_io_config_table);
}


/* TOUT19 pin configuration */

static const IfxPort_Io_ConfigPin tout19_pin_table[] = 
{
    IFXCFG_P00_10_IO_CONFIG
};

static const IfxPort_Io_Config tout19_io_config_table = 
{
    sizeof(tout19_pin_table)/sizeof(IfxPort_Io_ConfigPin),
    (IfxPort_Io_ConfigPin*)tout19_pin_table
};

extern void tout19_init_pins(void)
{
    IfxPort_Io_initModule(&tout19_io_config_table);
}

