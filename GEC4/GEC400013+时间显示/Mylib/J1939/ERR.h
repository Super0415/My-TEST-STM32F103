
#ifndef __ERR_H
#define __ERR_H

/*********************************************************************
    π ’œ¥˙¬Î∂®“Â
**********************************************************************/
		#define ERR_VERSION                    1000

		/* ********************** Speed Input ***************** */
		#define ERR_CODE_CRANK_SENSOR1         689
		#define ERR_CODE_CRANK_SENSOR2         778
		#define ERR_CODE_CAM_SENSOR            778
		#define ERR_CODE_VSS_SENSOR            241

		/* ******************* Speed Setpointer *************** */
		#define ERR_CODE_SETPOINT1_VHIGH       131
		#define ERR_CODE_SETPOINT1_VLOW        132
		#define ERR_CODE_SETPOINT2_VHIGH       133
		#define ERR_CODE_SETPOINT2_VLOW        134
		#define ERR_CODE_SETP1_SUB_VHIGH       1239
		#define ERR_CODE_SETP1_SUB_VLOW        1241

		/* ****************** Pressure Sensor ***************** */
		#define ERR_CODE_BOOST_PRESS_VHIGH     122
		#define ERR_CODE_BOOST_PRESS_VLOW      123
		#define ERR_CODE_OIL_PRESS_VHIGH       135
		#define ERR_CODE_OIL_PRESS_VLOW        141
		#define ERR_CODE_AMB_PRESS_VHIGH       221
		#define ERR_CODE_AMB_PRESS_VLOW        222
		#define ERR_CODE_RAIL_PRESS_VHIGH      451
		#define ERR_CODE_RAIL_PRESS_VLOW       452
		#define ERR_CODE_FUEL_PRESS_VHIGH      811  /* Self Def */
		#define ERR_CODE_FUEL_PRESS_VLOW       812  /* Self Def */

		/* ***************** Temperture Sensor **************** */
		#define ERR_CODE_COOL_TEMP_VHIGH       144
		#define ERR_CODE_COOL_TEMP_VLOW        145
		#define ERR_CODE_BOOST_TEMP_VHIGH      153
		#define ERR_CODE_BOOST_TEMP_VLOW       154
		#define ERR_CODE_OIL_TEMP_VHIGH        813  /* Self Def */
		#define ERR_CODE_OIL_TEMP_VLOW         814  /* Self Def */
		#define ERR_CODE_FUEL_TEMP_VHIGH       815  /* Self Def */
		#define ERR_CODE_FUEL_TEMP_VLOW        816  /* Self Def */
		#define ERR_CODE_EXH_TEMP_VHIGH        1665
		#define ERR_CODE_EXH_TEMP_VLOW         1666
		#define ERR_CODE_AMB_TEMP_VHIGH        249
		#define ERR_CODE_AMB_TEMP_VLOW         256

		/* ******************* Level Sensor ******************* */
		#define ERR_CODE_COOL_LEVEL_VHIGH      195
		#define ERR_CODE_COOL_LEVEL_VLOW       196

		/* ******************* Other Sensor ******************* */
		#define ERR_CODE_LOAD_INPUT_VHIGH      817  /* Self Def */
		#define ERR_CODE_LOAD_INPUT_VLOW       818  /* Self Def */
		#define ERR_CODE_SYNC_INPUT_VHIGH      821  /* Self Def */
		#define ERR_CODE_SYNC_INPUT_VLOW       822  /* Self Def */
		#define ERR_CODE_RACK_INPUT_VHIGH      823  /* Self Def */
		#define ERR_CODE_RACK_INPUT_VLOW       824  /* Self Def */
		#define ERR_CODE_RACK_CURRENT_VHIGH    825  /* Self Def */
		#define ERR_CODE_RACK_CURRENT_VLOW     826  /* Self Def */
		#define ERR_CODE_EGR_INPUT_VHIGH       2272
		#define ERR_CODE_EGR_INPUT_VLOW        2273
		#define ERR_CODE_BEGIN_INPUT_VHIGH     827  /* Self Def */
		#define ERR_CODE_BEGIN_INPUT_VLOW      828  /* Self Def */

		/* ********************* Actuators ******************** */
		#define ERR_CODE_RACK_ACTUATOR         831  /* Self Def */
		#define ERR_CODE_EGR_ACTUATOR          2357
		#define ERR_CODE_BEGIN_ACTUATOR        832  /* Self Def */
		#define ERR_CODE_ENGINE_STARTER        584
		#define ERR_CODE_INJECTOR1             322
		#define ERR_CODE_INJECTOR5             323
		#define ERR_CODE_INJECTOR3             324
		#define ERR_CODE_INJECTOR6             325
		#define ERR_CODE_INJECTOR2             331
		#define ERR_CODE_INJECTOR4             332

		/* ****************** Warn and Stop ******************* */
		#define ERR_CODE_OIL_PRESS_WARN        143
		#define ERR_CODE_OIL_PRESS_STOP        415
		#define ERR_CODE_COOL_TEMP_WARN        146
		#define ERR_CODE_COOL_TEMP_STOP        151
		#define ERR_CODE_BOOST_TEMP_WARN       488
		#define ERR_CODE_BOOST_TEMP_STOP       155
		#define ERR_CODE_OIL_TEMP_WARN         833  /* Self Def */
		#define ERR_CODE_OIL_TEMP_STOP         834  /* Self Def */
		#define ERR_CODE_FUEL_PRESS_WARN       559
		#define ERR_CODE_FUEL_PRESS_STOP       559
		#define ERR_CODE_RAIL_PRESS_WARN       553
		#define ERR_CODE_RAIL_PRESS_STOP       449
		#define ERR_CODE_COOL_LEVEL_WARN       197
		#define ERR_CODE_COOL_LEVEL_STOP       197
		#define ERR_CODE_OIL_LEVEL_WARN        471
		#define ERR_CODE_OIL_LEVEL_STOP        253

		/* **************** Other Monitoring ****************** */
		#define ERR_CODE_INTERN_TEMP           698
		#define ERR_CODE_BATT_VOLT_HIGH        441
		#define ERR_CODE_BATT_VOLT_LOW         442
		#define ERR_CODE_OVER_SPEED            234
		#define ERR_CODE_CAN_RX_TIMEOUT        285
		#define ERR_CODE_CAN_TX_TIMEOUT        286
		#define ERR_CODE_INTERN                111
		#define ERR_CODE_SPEED_DELTA           835  /* Self Def */
		#define ERR_CODE_RACK_DELTA            836  /* Self Def */
		#define ERR_CODE_RACK_WAVE             837  /* Self Def */

		/* ********************** Back up ********************* */
		#define ERR_CODE_LIN_RX_TIMEOUT        838  /* Self Def */
		#define ERR_CODE_LIN_TX_TIMEOUT        841  /* Self Def */
		#define ERR_CODE_BACKUP0               842  /* Self Def */
		#define ERR_CODE_BACKUP1               843  /* Self Def */
		#define ERR_CODE_BACKUP2               844  /* Self Def */

		/* ********************** Tong Jie ******************** */
		#define ERR_CODE_CHARG_VOLT_LOW        911  /* Self Def */
		#define ERR_CODE_CHARG_VOLT_HIGH       912  /* Self Def */
		#define ERR_CODE_PUMP_OIL_PRESS_LOW    913  /* Self Def */
		#define ERR_CODE_PUMP_OIL_TEMP_HIGH    914  /* Self Def */
		#define ERR_CODE_WP_IN_PRESS_LOW       915  /* Self Def */
		#define ERR_CODE_WP_OUT_PRESS_LOW      916  /* Self Def */
		#define ERR_CODE_WP_OUT_PRESS_HIGH     917  /* Self Def */
		#define ERR_CODE_WP_DIFF_PRESS_HIGH    918  /* Self Def */
		#define ERR_CODE_WP_USER_PRESS_HIGH    919  /* Self Def */
		#define ERR_CODE_WP_WATER_LEVEL_LOW    921  /* Self Def */
		#define ERR_CODE_WP_ENG_TIME_OVER      922  /* Self Def */
		#define ERR_CODE_COOL_TEMP2_VHIGH      923  /* Self Def */
		#define ERR_CODE_COOL_TEMP2_VLOW       924  /* Self Def */
		#define ERR_CODE_COOL_TEMP_DIFFER      925  /* Self Def */
		#define ERR_CODE_BOOST_TEMP2_VHIGH     926  /* Self Def */
		#define ERR_CODE_BOOST_TEMP2_VLOW      927  /* Self Def */
		#define ERR_CODE_BOOST_TEMP_DIFFER     928  /* Self Def */
		#define ERR_CODE_BOOST_PRESS2_VHIGH    931  /* Self Def */
		#define ERR_CODE_BOOST_PRESS2_VLOW     932  /* Self Def */
		#define ERR_CODE_BOOST_PRESS_DIFFER    933  /* Self Def */

		/* **************************************************** */
		/*  ERR_VERSION = 10xx: VEC1000 Application             */
		/*  ERR_VERSION = 68xx: VEC6800 Application             */
		/* **************************************************** */

		/* ********************** Speed Input ***************** */
		#define SPN_CODE_CRANK_SENSOR1         190
		#define SPN_CODE_CRANK_SENSOR2         636
		#define SPN_CODE_CAM_SENSOR            636
		#define SPN_CODE_VSS_SENSOR            84

		/* ******************* Speed Setpointer *************** */
		#define SPN_CODE_SETPOINT1_VHIGH       91
		#define SPN_CODE_SETPOINT1_VLOW        91
		#define SPN_CODE_SETPOINT2_VHIGH       243
		#define SPN_CODE_SETPOINT2_VLOW        243
		#define SPN_CODE_SETP1_SUB_VHIGH       29
		#define SPN_CODE_SETP1_SUB_VLOW        29

		/* ****************** Pressure Sensor ***************** */
		#define SPN_CODE_BOOST_PRESS_VHIGH     102
		#define SPN_CODE_BOOST_PRESS_VLOW      102
		#define SPN_CODE_OIL_PRESS_VHIGH       100
		#define SPN_CODE_OIL_PRESS_VLOW        100
		#define SPN_CODE_AMB_PRESS_VHIGH       108
		#define SPN_CODE_AMB_PRESS_VLOW        108
		#define SPN_CODE_RAIL_PRESS_VHIGH      157
		#define SPN_CODE_RAIL_PRESS_VLOW       157
		#define SPN_CODE_FUEL_PRESS_VHIGH      95
		#define SPN_CODE_FUEL_PRESS_VLOW       95

		/* ***************** Temperture Sensor **************** */
		#define SPN_CODE_COOL_TEMP_VHIGH       110
		#define SPN_CODE_COOL_TEMP_VLOW        110
		#define SPN_CODE_BOOST_TEMP_VHIGH      105
		#define SPN_CODE_BOOST_TEMP_VLOW       105
		#define SPN_CODE_OIL_TEMP_VHIGH        175
		#define SPN_CODE_OIL_TEMP_VLOW         175
		#define SPN_CODE_FUEL_TEMP_VHIGH       174
		#define SPN_CODE_FUEL_TEMP_VLOW        174
		#define SPN_CODE_EXH_TEMP_VHIGH        206
		#define SPN_CODE_EXH_TEMP_VLOW         206
		#define SPN_CODE_AMB_TEMP_VHIGH        171
		#define SPN_CODE_AMB_TEMP_VLOW         171

		/* ******************* Level Sensor ******************* */
		#define SPN_CODE_COOL_LEVEL_VHIGH      111
		#define SPN_CODE_COOL_LEVEL_VLOW       111

		/* ******************* Other Sensor ******************* */
		#define SPN_CODE_LOAD_INPUT_VHIGH      817
		#define SPN_CODE_LOAD_INPUT_VLOW       818
		#define SPN_CODE_SYNC_INPUT_VHIGH      821
		#define SPN_CODE_SYNC_INPUT_VLOW       822
		#define SPN_CODE_RACK_INPUT_VHIGH      823
		#define SPN_CODE_RACK_INPUT_VLOW       824
		#define SPN_CODE_RACK_CURRENT_VHIGH    825
		#define SPN_CODE_RACK_CURRENT_VLOW     826
		#define SPN_CODE_EGR_INPUT_VHIGH       2791
		#define SPN_CODE_EGR_INPUT_VLOW        2791
		#define SPN_CODE_BEGIN_INPUT_VHIGH     827
		#define SPN_CODE_BEGIN_INPUT_VLOW      828

		/* ********************* Actuators ******************** */
		#define SPN_CODE_RACK_ACTUATOR         831
		#define SPN_CODE_EGR_ACTUATOR          2791
		#define SPN_CODE_BEGIN_ACTUATOR        832
		#define SPN_CODE_ENGINE_STARTER        677
		#define SPN_CODE_INJECTOR1             651
		#define SPN_CODE_INJECTOR5             652
		#define SPN_CODE_INJECTOR3             653
		#define SPN_CODE_INJECTOR6             654
		#define SPN_CODE_INJECTOR2             655
		#define SPN_CODE_INJECTOR4             656

		/* ****************** Warn and Stop ******************* */
		#define SPN_CODE_OIL_PRESS_WARN        100
		#define SPN_CODE_OIL_PRESS_STOP        100
		#define SPN_CODE_COOL_TEMP_WARN        110
		#define SPN_CODE_COOL_TEMP_STOP        110
		#define SPN_CODE_BOOST_TEMP_WARN       102
		#define SPN_CODE_BOOST_TEMP_STOP       102
		#define SPN_CODE_OIL_TEMP_WARN         175
		#define SPN_CODE_OIL_TEMP_STOP         175
		#define SPN_CODE_FUEL_PRESS_WARN       174
		#define SPN_CODE_FUEL_PRESS_STOP       174
		#define SPN_CODE_RAIL_PRESS_WARN       157
		#define SPN_CODE_RAIL_PRESS_STOP       157
		#define SPN_CODE_COOL_LEVEL_WARN       111
		#define SPN_CODE_COOL_LEVEL_STOP       111
		#define SPN_CODE_OIL_LEVEL_WARN        98
		#define SPN_CODE_OIL_LEVEL_STOP        98

		/* **************** Other Monitoring ****************** */
		#define SPN_CODE_INTERN_TEMP           630
		#define SPN_CODE_BATT_VOLT_HIGH        168
		#define SPN_CODE_BATT_VOLT_LOW         168
		#define SPN_CODE_OVER_SPEED            533
		#define SPN_CODE_CAN_RX_TIMEOUT        898
		#define SPN_CODE_CAN_TX_TIMEOUT        898
		#define SPN_CODE_INTERN                630
		#define SPN_CODE_SPEED_DELTA           835
		#define SPN_CODE_RACK_DELTA            836
		#define SPN_CODE_RACK_WAVE             837

		/* ********************** Back up ********************* */
		#define SPN_CODE_LIN_RX_TIMEOUT        838  /* Self Def */
		#define SPN_CODE_LIN_TX_TIMEOUT        841  /* Self Def */
		#define SPN_CODE_BACKUP0               842  /* Self Def */
		#define SPN_CODE_BACKUP1               843  /* Self Def */
		#define SPN_CODE_BACKUP2               844  /* Self Def */

		/* ********************** Tong Jie ******************** */
		#define SPN_CODE_CHARG_VOLT_LOW        911  /* Self Def */
		#define SPN_CODE_CHARG_VOLT_HIGH       912  /* Self Def */
		#define SPN_CODE_PUMP_OIL_PRESS_LOW    913  /* Self Def */
		#define SPN_CODE_PUMP_OIL_TEMP_HIGH    914  /* Self Def */
		#define SPN_CODE_WP_IN_PRESS_LOW       915  /* Self Def */
		#define SPN_CODE_WP_OUT_PRESS_LOW      916  /* Self Def */
		#define SPN_CODE_WP_OUT_PRESS_HIGH     917  /* Self Def */
		#define SPN_CODE_WP_DIFF_PRESS_HIGH    918  /* Self Def */
		#define SPN_CODE_WP_USER_PRESS_HIGH    919  /* Self Def */
		#define SPN_CODE_WP_WATER_LEVEL_LOW    921  /* Self Def */
		#define SPN_CODE_WP_ENG_TIME_OVER      922  /* Self Def */
		#define SPN_CODE_COOL_TEMP2_VHIGH      110  /* ST Used  */
		#define SPN_CODE_COOL_TEMP2_VLOW       110  /* ST Used  */
		#define SPN_CODE_COOL_TEMP_DIFFER      110  /* ST Used  */
		#define SPN_CODE_BOOST_TEMP2_VHIGH     105  /* ST Used  */
		#define SPN_CODE_BOOST_TEMP2_VLOW      105  /* ST Used  */
		#define SPN_CODE_BOOST_TEMP_DIFFER     105  /* ST Used  */
		#define SPN_CODE_BOOST_PRESS2_VHIGH    102  /* ST Used  */
		#define SPN_CODE_BOOST_PRESS2_VLOW     102  /* ST Used  */
		#define SPN_CODE_BOOST_PRESS_DIFFER    102  /* ST Used  */


		#define FMI_CODE_CRANK_SENSOR1         12
		#define FMI_CODE_CRANK_SENSOR2         12
		#define FMI_CODE_CAM_SENSOR            12
		#define FMI_CODE_VSS_SENSOR            11

		/* ******************* Speed Setpointer *************** */
		#define FMI_CODE_SETPOINT1_VHIGH       3
		#define FMI_CODE_SETPOINT1_VLOW        4
		#define FMI_CODE_SETPOINT2_VHIGH       3
		#define FMI_CODE_SETPOINT2_VLOW        4
		#define FMI_CODE_SETP1_SUB_VHIGH       3
		#define FMI_CODE_SETP1_SUB_VLOW        4

		/* ****************** Pressure Sensor ***************** */
		#define FMI_CODE_BOOST_PRESS_VHIGH     3
		#define FMI_CODE_BOOST_PRESS_VLOW      4
		#define FMI_CODE_OIL_PRESS_VHIGH       3
		#define FMI_CODE_OIL_PRESS_VLOW        4
		#define FMI_CODE_AMB_PRESS_VHIGH       3
		#define FMI_CODE_AMB_PRESS_VLOW        4
		#define FMI_CODE_RAIL_PRESS_VHIGH      3
		#define FMI_CODE_RAIL_PRESS_VLOW       4
		#define FMI_CODE_FUEL_PRESS_VHIGH      3
		#define FMI_CODE_FUEL_PRESS_VLOW       4

		/* ***************** Temperture Sensor **************** */
		#define FMI_CODE_COOL_TEMP_VHIGH       3
		#define FMI_CODE_COOL_TEMP_VLOW        4
		#define FMI_CODE_BOOST_TEMP_VHIGH      3
		#define FMI_CODE_BOOST_TEMP_VLOW       4
		#define FMI_CODE_OIL_TEMP_VHIGH        3
		#define FMI_CODE_OIL_TEMP_VLOW         4
		#define FMI_CODE_FUEL_TEMP_VHIGH       3
		#define FMI_CODE_FUEL_TEMP_VLOW        4
		#define FMI_CODE_EXH_TEMP_VHIGH        3
		#define FMI_CODE_EXH_TEMP_VLOW         4
		#define FMI_CODE_AMB_TEMP_VHIGH        3
		#define FMI_CODE_AMB_TEMP_VLOW         4

		/* ******************* Level Sensor ******************* */
		#define FMI_CODE_COOL_LEVEL_VHIGH      3
		#define FMI_CODE_COOL_LEVEL_VLOW       4

		/* ******************* Other Sensor ******************* */
		#define FMI_CODE_LOAD_INPUT_VHIGH      3
		#define FMI_CODE_LOAD_INPUT_VLOW       4
		#define FMI_CODE_SYNC_INPUT_VHIGH      3
		#define FMI_CODE_SYNC_INPUT_VLOW       4
		#define FMI_CODE_RACK_INPUT_VHIGH      3
		#define FMI_CODE_RACK_INPUT_VLOW       4
		#define FMI_CODE_RACK_CURRENT_VHIGH    3
		#define FMI_CODE_RACK_CURRENT_VLOW     4
		#define FMI_CODE_EGR_INPUT_VHIGH       3
		#define FMI_CODE_EGR_INPUT_VLOW        4
		#define FMI_CODE_BEGIN_INPUT_VHIGH     3
		#define FMI_CODE_BEGIN_INPUT_VLOW      4

		/* ********************* Actuators ******************** */
		#define FMI_CODE_RACK_ACTUATOR         2
		#define FMI_CODE_EGR_ACTUATOR          2
		#define FMI_CODE_BEGIN_ACTUATOR        2
		#define FMI_CODE_ENGINE_STARTER        2
		#define FMI_CODE_INJECTOR1             2
		#define FMI_CODE_INJECTOR5             2
		#define FMI_CODE_INJECTOR3             2
		#define FMI_CODE_INJECTOR6             2
		#define FMI_CODE_INJECTOR2             2
		#define FMI_CODE_INJECTOR4             2

		/* ****************** Warn and Stop ******************* */
		#define FMI_CODE_OIL_PRESS_WARN        17
		#define FMI_CODE_OIL_PRESS_STOP        17
		#define FMI_CODE_COOL_TEMP_WARN        15
		#define FMI_CODE_COOL_TEMP_STOP        15
		#define FMI_CODE_BOOST_TEMP_WARN       2
		#define FMI_CODE_BOOST_TEMP_STOP       2
		#define FMI_CODE_OIL_TEMP_WARN         2
		#define FMI_CODE_OIL_TEMP_STOP         2
		#define FMI_CODE_FUEL_PRESS_WARN       2
		#define FMI_CODE_FUEL_PRESS_STOP       2
		#define FMI_CODE_RAIL_PRESS_WARN       2
		#define FMI_CODE_RAIL_PRESS_STOP       2
		#define FMI_CODE_COOL_LEVEL_WARN       2
		#define FMI_CODE_COOL_LEVEL_STOP       2
		#define FMI_CODE_OIL_LEVEL_WARN        2
		#define FMI_CODE_OIL_LEVEL_STOP        2

		/* **************** Other Monitoring ****************** */
		#define FMI_CODE_INTERN_TEMP           2
		#define FMI_CODE_BATT_VOLT_HIGH        3
		#define FMI_CODE_BATT_VOLT_LOW         4
		#define FMI_CODE_OVER_SPEED            15
		#define FMI_CODE_CAN_RX_TIMEOUT        11
		#define FMI_CODE_CAN_TX_TIMEOUT        12
		#define FMI_CODE_INTERN                2
		#define FMI_CODE_SPEED_DELTA           2
		#define FMI_CODE_RACK_DELTA            2
		#define FMI_CODE_RACK_WAVE             2

		/* ********************** Back up ********************* */
		#define FMI_CODE_LIN_RX_TIMEOUT        2    /* Self Def */
		#define FMI_CODE_LIN_TX_TIMEOUT        2    /* Self Def */
		#define FMI_CODE_BACKUP0               2    /* Self Def */
		#define FMI_CODE_BACKUP1               2    /* Self Def */
		#define FMI_CODE_BACKUP2               2    /* Self Def */

		/* ********************** Tong Jie ******************** */
		#define FMI_CODE_CHARG_VOLT_LOW        2    /* Self Def */
		#define FMI_CODE_CHARG_VOLT_HIGH       2    /* Self Def */
		#define FMI_CODE_PUMP_OIL_PRESS_LOW    2    /* Self Def */
		#define FMI_CODE_PUMP_OIL_TEMP_HIGH    2    /* Self Def */
		#define FMI_CODE_WP_IN_PRESS_LOW       2    /* Self Def */
		#define FMI_CODE_WP_OUT_PRESS_LOW      2    /* Self Def */
		#define FMI_CODE_WP_OUT_PRESS_HIGH     2    /* Self Def */
		#define FMI_CODE_WP_DIFF_PRESS_HIGH    2    /* Self Def */
		#define FMI_CODE_WP_USER_PRESS_HIGH    2    /* Self Def */
		#define FMI_CODE_WP_WATER_LEVEL_LOW    2    /* Self Def */
		#define FMI_CODE_WP_ENG_TIME_OVER      2    /* Self Def */
		#define FMI_CODE_COOL_TEMP2_VHIGH      5    /* Self Def */
		#define FMI_CODE_COOL_TEMP2_VLOW       6    /* ST Used  */
		#define FMI_CODE_COOL_TEMP_DIFFER      13   /* ST Used  */
		#define FMI_CODE_BOOST_TEMP2_VHIGH     5    /* ST Used  */
		#define FMI_CODE_BOOST_TEMP2_VLOW      6    /* ST Used  */
		#define FMI_CODE_BOOST_TEMP_DIFFER     13   /* ST Used  */
		#define FMI_CODE_BOOST_PRESS2_VHIGH    5    /* ST Used  */
		#define FMI_CODE_BOOST_PRESS2_VLOW     6    /* ST Used  */
		#define FMI_CODE_BOOST_PRESS_DIFFER    13   /* ST Used  */

#endif
/* **************************************************** */
/*                        The End                       */
/* **************************************************** */

