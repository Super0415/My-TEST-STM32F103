/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File XIOCortex.c                        */
/*                            By: Wu Xuekui                             */
/*                             2014-10-14                               */
/* ******************************************************************** */

#define   XIO_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              XIOInit()                               */
/* ******************************************************************** */
void XIOInit (void)
{
	usXIOTimer = 0;
    usXIOStatus = 0;
    usXIOCalcTime = 0;
    usXIOAdcChEff0 = 0;
    usXIOAdcChEff1 = 0;
    usXIOAdcChEff2 = 0;
    usXIOAdcChEff3 = 0;
    usXIOAdcChEff4 = 0;
    usXIOAdcChEff5 = 0;
    usXIOAdcChEff6 = 0;
    usXIOAdcChEff7 = 0;
    usXIOAdcChEff8 = 0;
    usXIOAdcChEff03 = 0;
    usXIOAdcChEff06 = 0;
    usXIOAdcChEff36 = 0;
    usXIOAdcChEff14 = 0;
    usXIOAdcChEff17 = 0;
    usXIOAdcChEff47 = 0;
    usXIOAdcChEffGd = 0;
    siXIOCrossMac12 = 0;
    siXIOCrossMac45 = 0;
    siXIOCrossMac78 = 0;
    usXIOHardFreqMainA = 0;
    usXIOSoftFreqMainA = 0;
    usXIOSoftFreqMainB = 0;
    usXIOSoftFreqMainC = 0;
    usXIOHardFreqGensA = 0;
    usXIOSoftFreqGensA = 0;
    usXIOSoftFreqGensB = 0;
    usXIOSoftFreqGensC = 0;
    uiXIOMainActPrd = 0;
    uiXIOHardPrdMainA = 0;
    uiXIOSoftPrdMainA = 0;
    uiXIOSoftPrdMainB = 0;
    uiXIOSoftPrdMainC = 0;
    uiXIOGensActPrd = 0;
    uiXIOHardPrdGensA = 0;
    uiXIOSoftPrdGensA = 0;
    uiXIOSoftPrdGensB = 0;
    uiXIOSoftPrdGensC = 0;
    ssXIOSoftPhsDiffer = 0;
    ssXIOHardPhsDiffer = 0;
    usXIOMainSmpSiz = XIO_ADC_SMPL_SIZ;
    usXIOGensSmpSiz = XIO_ADC_SMPL_SIZ;
    pXIOAdcDmaBuf   = &usXIOAdcDmaBuf0[0];    //DMA读取ADC数据地址
    pXIOFftDatBuf   = &ssXIOAdcChDat0[0];
    usXIOAdcChRef0  =  usDBpAdcChRef0;
    usXIOAdcChRef1  =  usDBpAdcChRef1;
    usXIOAdcChRef2  =  usDBpAdcChRef2;
    usXIOAdcChRef3  =  usDBpAdcChRef3;
    usXIOAdcChRef4  =  usDBpAdcChRef4;
    usXIOAdcChRef5  =  usDBpAdcChRef5;
    usXIOAdcChRef6  =  usDBpAdcChRef6;
    usXIOAdcChRef7  =  usDBpAdcChRef7;
    usXIOAdcChRef8  =  usDBpAdcChRef8;
    uiXIOAdcRefSum0 = (INT32U)usXIOAdcChRef0 * XIO_ADC_REF_FILTER;  //固定基准值   *  滤波点数
    uiXIOAdcRefSum1 = (INT32U)usXIOAdcChRef1 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum2 = (INT32U)usXIOAdcChRef2 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum3 = (INT32U)usXIOAdcChRef3 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum4 = (INT32U)usXIOAdcChRef4 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum5 = (INT32U)usXIOAdcChRef5 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum6 = (INT32U)usXIOAdcChRef6 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum7 = (INT32U)usXIOAdcChRef7 * XIO_ADC_REF_FILTER;
    uiXIOAdcRefSum8 = (INT32U)usXIOAdcChRef8 * XIO_ADC_REF_FILTER;
		
    SFSoftFreqInit(&sXIOSoftFreq0, usDBpAdcChFilter0);
    SFSoftFreqInit(&sXIOSoftFreq1, usDBpAdcChFilter1);
    SFSoftFreqInit(&sXIOSoftFreq2, usDBpAdcChFilter2);
    SFSoftFreqInit(&sXIOSoftFreq3, usDBpAdcChFilter3);
    SFSoftFreqInit(&sXIOSoftFreq4, usDBpAdcChFilter4);
    SFSoftFreqInit(&sXIOSoftFreq5, usDBpAdcChFilter5);
    SFSoftFreqInit(&sXIOSoftFreq6, usDBpAdcChFilter6);
    SFSoftFreqInit(&sXIOSoftFreq7, usDBpAdcChFilter7);
    SFSoftFreqInit(&sXIOSoftFreq8, usDBpAdcChFilter8);
    SFHardFreqInit(&sXIOHardFreq0);
    SFHardFreqInit(&sXIOHardFreq1);
    SFSpdPulseInit(&sXIOSpdPulse0, usDBpTeethCrank1, usDBpSpeedFilter1);
    SFSpdPulseInit(&sXIOSpdPulse1, usDBpTeethCrank2, usDBpSpeedFilter2);
		
    (void)XIOResetGPIO(GPIOA);  //复位GPIOA
    (void)XIOResetGPIO(GPIOB);  //复位GPIOB
    (void)XIOResetGPIO(GPIOC);
    (void)XIOResetGPIO(GPIOD);
    (void)XIOResetGPIO(GPIOE);
//    
//    (void)XIOInitTim3FrqIn();
//    (void)XIOInitTim4PwmOut();   
//         
//    (void)XIOInitDigInput();    //开关量输入初始化
//    (void)XIOInitDigOutput();   //开关量输出初始化
    (void)XIOInitADC1();        //ADC1初始化
    (void)XIOInitDma1Ch1Adc();
    (void)XIOInitTim1();
//    (void)XIOInitTim2();
//    (void)XIOInitTim3();
// //   (void)XIOInitTim3FrqIn();
//    (void)XIOInitTim4();
// //   (void)XIOInitTim4PwmOut();
//    (void)CTLInit();
}

/* ******************************************************************** */
/*                              XIOStart()                              */
/* ******************************************************************** */
void XIOStart (void)
{   (void)XIOInitTim1AdcTriger();
    (void)FWIrqEnable(DMA1_Channel1_IRQn, 0);
    (void)FWIrqEnable(TIM2_IRQn, 0);
}

/* ******************************************************************** */
/*                            XIOTaskLoop()                             */
/* ******************************************************************** */
void XIOTaskLoop (void)
{   INT16U usBeg, usSiz, usTim;
  //  (void)FWWatchdogInit();
    while (1)
    {   (void)OSTaskSuspend(OS_PRIO_SELF);
//  //      (void)FWWatchdogFeed();
//        usTim = XIO_GET_FREE_TIMER();                                  //读取计时器寄存器数值
        /* ************************************************************ */
        /*                     Read Analog Input      获取AD值数据      */
        /* ************************************************************ */
        (void)XIOGetAdcChanDat(pXIOAdcDmaBuf);
        /* ************************************************************ */
        /*                    Get Channel Average  取其平均值过滤AD值   */
        /* ************************************************************ */
        usDBmAdcInput0  = SFGetAve16s(ssXIOAdcChDat0, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput1  = SFGetAve16s(ssXIOAdcChDat1, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput2  = SFGetAve16s(ssXIOAdcChDat2, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput3  = SFGetAve16s(ssXIOAdcChDat3, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput4  = SFGetAve16s(ssXIOAdcChDat4, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput5  = SFGetAve16s(ssXIOAdcChDat5, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput6  = SFGetAve16s(ssXIOAdcChDat6, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput7  = SFGetAve16s(ssXIOAdcChDat7, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput8  = SFGetAve16s(ssXIOAdcChDat8, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput9  = SFGetAve16s(ssXIOAdcChDat9, XIO_ADC_SMPL_SIZ);
        usDBmAdcInput10 = SFGetAve16s(ssXIOAdcChDat10,XIO_ADC_SMPL_SIZ);
        usDBmAdcInput11 = SFGetAve16s(ssXIOAdcChDat11,XIO_ADC_SMPL_SIZ);   //油压采集
        usDBmAdcInput12 = SFGetAve16s(ssXIOAdcChDat12,XIO_ADC_SMPL_SIZ);
        usDBmAdcInput13 = SFGetAve16s(ssXIOAdcChDat13,XIO_ADC_SMPL_SIZ);
        usDBmAdcInput14 = SFGetAve16s(ssXIOAdcChDat14,XIO_ADC_SMPL_SIZ);
        usDBmAdcInput15 = SFGetAve16s(ssXIOAdcChDat15,XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                    Get Channel Reference                     */
        /* ************************************************************ */
        if (usDBpAdcRefAutoOrFixed != 0)
        {   usXIOAdcChRef0 = SFGetAdcRef16u(usDBmAdcInput0, &uiXIOAdcRefSum0);
            usXIOAdcChRef1 = SFGetAdcRef16u(usDBmAdcInput1, &uiXIOAdcRefSum1);
            usXIOAdcChRef2 = SFGetAdcRef16u(usDBmAdcInput2, &uiXIOAdcRefSum2);
            usXIOAdcChRef3 = SFGetAdcRef16u(usDBmAdcInput3, &uiXIOAdcRefSum3);
            usXIOAdcChRef4 = SFGetAdcRef16u(usDBmAdcInput4, &uiXIOAdcRefSum4);
            usXIOAdcChRef5 = SFGetAdcRef16u(usDBmAdcInput5, &uiXIOAdcRefSum5);
            usXIOAdcChRef6 = SFGetAdcRef16u(usDBmAdcInput6, &uiXIOAdcRefSum6);
            usXIOAdcChRef7 = SFGetAdcRef16u(usDBmAdcInput7, &uiXIOAdcRefSum7);
            usXIOAdcChRef8 = SFGetAdcRef16u(usDBmAdcInput8, &uiXIOAdcRefSum8);
        }
        /* ************************************************************ */
        /*                      Data Sub Reference                      */
        /* ************************************************************ */
        (void)SFSubRef16s(ssXIOAdcChDat0, usXIOAdcChRef0, XIO_ADC_SMPL_SIZ);
        (void)SFSubRef16s(ssXIOAdcChDat1, usXIOAdcChRef1, XIO_ADC_SMPL_SIZ);
        (void)SFSubRef16s(ssXIOAdcChDat2, usXIOAdcChRef2, XIO_ADC_SMPL_SIZ);
        (void)SFSubRef16s(ssXIOAdcChDat3, usXIOAdcChRef3, XIO_ADC_SMPL_SIZ);
        (void)SFSubRef16s(ssXIOAdcChDat4, usXIOAdcChRef4, XIO_ADC_SMPL_SIZ);
        (void)SFSubRef16s(ssXIOAdcChDat5, usXIOAdcChRef5, XIO_ADC_SMPL_SIZ);
        (void)SFSubRef16s(ssXIOAdcChDat6, usXIOAdcChRef6, XIO_ADC_SMPL_SIZ);
        (void)SFSubRef16s(ssXIOAdcChDat7, usXIOAdcChRef7, XIO_ADC_SMPL_SIZ);
        (void)SFSubRef16s(ssXIOAdcChDat8, usXIOAdcChRef8, XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                     Adjust Data Array                        */
        /* ************************************************************ */
        (void)SFCopy16s(&ssXIOAdcArray0[XIO_ADC_SMPL_SIZ],
                        &ssXIOAdcArray0[0],
                        XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcArray1[XIO_ADC_SMPL_SIZ],
                        &ssXIOAdcArray1[0],
                        XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcArray2[XIO_ADC_SMPL_SIZ],
                        &ssXIOAdcArray2[0],
                        XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcArray3[XIO_ADC_SMPL_SIZ],
                        &ssXIOAdcArray3[0],
                        XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcArray4[XIO_ADC_SMPL_SIZ],
                        &ssXIOAdcArray4[0],
                        XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcArray5[XIO_ADC_SMPL_SIZ],
                        &ssXIOAdcArray5[0],
                        XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcArray6[XIO_ADC_SMPL_SIZ],
                        &ssXIOAdcArray6[0],
                        XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcArray7[XIO_ADC_SMPL_SIZ],
                        &ssXIOAdcArray7[0],
                        XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcArray8[XIO_ADC_SMPL_SIZ],
                        &ssXIOAdcArray8[0],
                        XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                     Copy Adc Data To Array                   */
        /* ************************************************************ */
        (void)SFCopy16s(&ssXIOAdcChDat0[0],
                        &ssXIOAdcArray0[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                        XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcChDat1[0],
                        &ssXIOAdcArray1[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                        XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcChDat2[0],
                        &ssXIOAdcArray2[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                        XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcChDat3[0],
                        &ssXIOAdcArray3[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                        XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcChDat4[0],
                        &ssXIOAdcArray4[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                        XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcChDat5[0],
                        &ssXIOAdcArray5[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                        XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcChDat6[0],
                        &ssXIOAdcArray6[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                        XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcChDat7[0],
                        &ssXIOAdcArray7[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                        XIO_ADC_SMPL_SIZ);
        (void)SFCopy16s(&ssXIOAdcChDat8[0],
                        &ssXIOAdcArray8[XIO_ADC_ARRAY_SIZ-XIO_ADC_SMPL_SIZ],
                        XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                    Find Zero Cross Points                    */
        /* ************************************************************ */
        (void)SFSoftFreqRefresh(&ssXIOAdcChDat0[0],
                                &sXIOSoftFreq0, XIO_ADC_SMPL_SIZ);
        (void)SFSoftFreqRefresh(&ssXIOAdcChDat1[0],
                                &sXIOSoftFreq1, XIO_ADC_SMPL_SIZ);
        (void)SFSoftFreqRefresh(&ssXIOAdcChDat3[0],
                                &sXIOSoftFreq3, XIO_ADC_SMPL_SIZ);
        (void)SFSoftFreqRefresh(&ssXIOAdcChDat4[0],
                                &sXIOSoftFreq4, XIO_ADC_SMPL_SIZ);
        (void)SFSoftFreqRefresh(&ssXIOAdcChDat6[0],
                                &sXIOSoftFreq6, XIO_ADC_SMPL_SIZ);
        (void)SFSoftFreqRefresh(&ssXIOAdcChDat7[0],
                                &sXIOSoftFreq7, XIO_ADC_SMPL_SIZ);
        /* ************************************************************ */
        /*                     Get Period and Phase                     */
        /* ************************************************************ */
        uiXIOSoftPrdMainA  = sXIOSoftFreq0.uiTPrd;
        usXIOSoftFreqMainA = sXIOSoftFreq0.usFreq;
        usXIOSoftPhsMainA  = sXIOSoftFreq0.usPhase;
        uiXIOSoftPrdMainB  = sXIOSoftFreq3.uiTPrd;
        usXIOSoftFreqMainB = sXIOSoftFreq3.usFreq;
        usXIOSoftPhsMainB  = sXIOSoftFreq3.usPhase;
        uiXIOSoftPrdMainC  = sXIOSoftFreq6.uiTPrd;
        usXIOSoftFreqMainC = sXIOSoftFreq6.usFreq;
        usXIOSoftPhsMainC  = sXIOSoftFreq6.usPhase;
        uiXIOSoftPrdGensA  = sXIOSoftFreq1.uiTPrd;
        usXIOSoftFreqGensA = sXIOSoftFreq1.usFreq;
        usXIOSoftPhsGensA  = sXIOSoftFreq1.usPhase;
        uiXIOSoftPrdGensB  = sXIOSoftFreq4.uiTPrd;
        usXIOSoftFreqGensB = sXIOSoftFreq4.usFreq;
        usXIOSoftPhsGensB  = sXIOSoftFreq4.usPhase;
        uiXIOSoftPrdGensC  = sXIOSoftFreq7.uiTPrd;
        usXIOSoftFreqGensC = sXIOSoftFreq7.usFreq;
        usXIOSoftPhsGensC  = sXIOSoftFreq7.usPhase;
        ssXIOSoftPhsDiffer = usXIOSoftPhsGensA - usXIOSoftPhsMainA;
        usDBmMainPhaseAB   = usXIOSoftPhsMainB - usXIOSoftPhsMainA;
        usDBmMainPhaseBC   = usXIOSoftPhsMainC - usXIOSoftPhsMainB;
        usDBmMainPhaseCA   = usXIOSoftPhsMainA - usXIOSoftPhsMainC;
        usDBmGensPhaseAB   = usXIOSoftPhsGensB - usXIOSoftPhsGensA;
        usDBmGensPhaseBC   = usXIOSoftPhsGensC - usXIOSoftPhsGensB;
        usDBmGensPhaseCA   = usXIOSoftPhsGensA - usXIOSoftPhsGensC;
        /* ************************************************************ */
        /*                     Get Hard Period                          */
        /* ************************************************************ */
        (void)SFHardFreqRefresh(&sXIOHardFreq0);
        (void)SFHardFreqRefresh(&sXIOHardFreq1);
        uiXIOHardPrdMainA  = SFHardFreqGetPeriod(&sXIOHardFreq0);
        uiXIOHardPrdGensA  = SFHardFreqGetPeriod(&sXIOHardFreq1);
        usXIOHardFreqMainA = SFHardFreqGetFreq(&sXIOHardFreq0);
        usXIOHardFreqGensA = SFHardFreqGetFreq(&sXIOHardFreq1);
        ssXIOHardPhsDiffer = SFHardFreqGetPhsDiff(&sXIOHardFreq0,&sXIOHardFreq1);
        /* ************************************************************ */
        /*             Get Main and Gens Period, Freq, Differ           */
        /* ************************************************************ */
        if (SFHardFreqCheckPeriod(&sXIOHardFreq0) != SF_FALSE)
        {   XIO_STS_CLR_BIT(XIO_STS_HARDPRD0_ERR);
            uiXIOMainActPrd  = uiXIOHardPrdMainA;
            usDBmMainFreq    = usXIOHardFreqMainA;
        }   else
        {   XIO_STS_SET_BIT(XIO_STS_HARDPRD0_ERR);
            uiXIOMainActPrd  = uiXIOSoftPrdMainA;
            usDBmMainFreq    = usXIOSoftFreqMainA;
        }
        if (SFHardFreqCheckPeriod(&sXIOHardFreq1) != SF_FALSE)
        {   XIO_STS_CLR_BIT(XIO_STS_HARDPRD1_ERR);
            uiXIOGensActPrd  = uiXIOHardPrdGensA;
            usDBmGensFreq    = usXIOHardFreqGensA;
        }   else
        {   XIO_STS_SET_BIT(XIO_STS_HARDPRD1_ERR);
            uiXIOGensActPrd  = uiXIOSoftPrdGensA;
            usDBmGensFreq    = usXIOSoftFreqGensA;
        }
        if (XIO_STS_GET_BIT(XIO_STS_HARDPRD_BOTH) == 0)
        {   ssDBmPhaseDiffer = ssXIOHardPhsDiffer;
            ssDBmFreqDiffer  = usXIOHardFreqGensA - usXIOHardFreqMainA;
        }   else
        {   ssDBmPhaseDiffer = ssXIOSoftPhsDiffer;
            ssDBmFreqDiffer  = usXIOSoftFreqGensA - usXIOSoftFreqMainA;
        }
        /* ************************************************************ */
        /*                         Get Main Voltage                     */
        /* ************************************************************ */
        usSiz = (INT16U)((uiXIOMainActPrd+XIO_ADC_SMPL_TIM_US/2)/XIO_ADC_SMPL_TIM_US);
        if((usSiz < (XIO_ADC_SMPL_SIZ/2)) || (usSiz >= XIO_ADC_ARRAY_SIZ))
        {   usSiz =  XIO_ADC_SMPL_SIZ;
        }
        usBeg           = XIO_ADC_ARRAY_SIZ - usSiz;
        usXIOMainSmpSiz = usSiz;
        usXIOAdcChEff0  = SFGetEffAve(&ssXIOAdcArray0[usBeg], usSiz);
        usXIOAdcChEff3  = SFGetEffAve(&ssXIOAdcArray3[usBeg], usSiz);
        usXIOAdcChEff6  = SFGetEffAve(&ssXIOAdcArray6[usBeg], usSiz);
        usXIOAdcChEff03 = SFSubEffAve(&ssXIOAdcArray0[usBeg],
                                      &ssXIOAdcArray3[usBeg], usSiz);
        usXIOAdcChEff06 = SFSubEffAve(&ssXIOAdcArray0[usBeg],
                                      &ssXIOAdcArray6[usBeg], usSiz);
        usXIOAdcChEff36 = SFSubEffAve(&ssXIOAdcArray3[usBeg],
                                      &ssXIOAdcArray6[usBeg], usSiz);
        usDBmMainVoltA  = SF_GET_VOLT_LN(usXIOAdcChEff0, usDBpAmpMainVoltA);
        usDBmMainVoltB  = SF_GET_VOLT_LN(usXIOAdcChEff3, usDBpAmpMainVoltB);
        usDBmMainVoltC  = SF_GET_VOLT_LN(usXIOAdcChEff6, usDBpAmpMainVoltC);
        usDBmMainVoltAB = SF_GET_VOLT_LL(usXIOAdcChEff03,usDBpAmpMainVoltAB);
        usDBmMainVoltBC = SF_GET_VOLT_LL(usXIOAdcChEff06,usDBpAmpMainVoltBC);
        usDBmMainVoltCA = SF_GET_VOLT_LL(usXIOAdcChEff36,usDBpAmpMainVoltCA);
        /* ************************************************************ */
        /*                  Get Gens Voltage and Current                */
        /* ************************************************************ */
        usSiz = (INT16U)((uiXIOGensActPrd+XIO_ADC_SMPL_TIM_US/2)/XIO_ADC_SMPL_TIM_US);
        if((usSiz < (XIO_ADC_SMPL_SIZ/2)) || (usSiz >= XIO_ADC_ARRAY_SIZ))
        {   usSiz =  XIO_ADC_SMPL_SIZ;
        }
        usBeg           = XIO_ADC_ARRAY_SIZ - usSiz;
        usXIOGensSmpSiz = usSiz;
        usXIOAdcChEff1  = SFGetEffAve(&ssXIOAdcArray1[usBeg], usSiz);
        usXIOAdcChEff4  = SFGetEffAve(&ssXIOAdcArray4[usBeg], usSiz);
        usXIOAdcChEff7  = SFGetEffAve(&ssXIOAdcArray7[usBeg], usSiz);
        usXIOAdcChEff2  = SFGetEffAve(&ssXIOAdcArray2[usBeg], usSiz);
        usXIOAdcChEff5  = SFGetEffAve(&ssXIOAdcArray5[usBeg], usSiz);
        usXIOAdcChEff8  = SFGetEffAve(&ssXIOAdcArray8[usBeg], usSiz);
        usXIOAdcChEff14 = SFSubEffAve(&ssXIOAdcArray1[usBeg],
                                      &ssXIOAdcArray4[usBeg], usSiz);
        usXIOAdcChEff17 = SFSubEffAve(&ssXIOAdcArray1[usBeg],
                                      &ssXIOAdcArray7[usBeg], usSiz);
        usXIOAdcChEff47 = SFSubEffAve(&ssXIOAdcArray4[usBeg],
                                      &ssXIOAdcArray7[usBeg], usSiz);
        usXIOAdcChEffGd = SFTriEffAve(&ssXIOAdcArray2[usBeg],
                                      &ssXIOAdcArray5[usBeg],
                                      &ssXIOAdcArray8[usBeg], usSiz);
        usDBmGensVoltA  = SF_GET_VOLT_LN(usXIOAdcChEff1, usDBpAmpGensVoltA);    //获取A相电压
        usDBmGensVoltB  = SF_GET_VOLT_LN(usXIOAdcChEff4, usDBpAmpGensVoltB);    //获取B相电压
        usDBmGensVoltC  = SF_GET_VOLT_LN(usXIOAdcChEff7, usDBpAmpGensVoltC);    //获取C相电压
        usDBmGensVoltAB = SF_GET_VOLT_LL(usXIOAdcChEff14,usDBpAmpGensVoltAB);
        usDBmGensVoltBC = SF_GET_VOLT_LL(usXIOAdcChEff17,usDBpAmpGensVoltBC);
        usDBmGensVoltCA = SF_GET_VOLT_LL(usXIOAdcChEff47,usDBpAmpGensVoltCA);
        usDBmGensCurrA  = SF_GET_CURRENT(usXIOAdcChEff2, usDBpAmpGensCurrA, usDBpGensCtRatio);
        usDBmGensCurrB  = SF_GET_CURRENT(usXIOAdcChEff5, usDBpAmpGensCurrB, usDBpGensCtRatio);
        usDBmGensCurrC  = SF_GET_CURRENT(usXIOAdcChEff8, usDBpAmpGensCurrC, usDBpGensCtRatio);
        usBeg           = (usDBpAmpGensCurrA + usDBpAmpGensCurrB + usDBpAmpGensCurrC) / 3;
        usDBmGensCurrGd = SF_GET_CURRENT(usXIOAdcChEffGd, usBeg, usDBpGensCtRatio);
        ssDBmVoltDiffer = usDBmGensVoltA - usDBmMainVoltA;
        /* ************************************************************ */
        /*                        Get Active Power                      */
        /* ************************************************************ */
        usSiz           = usXIOGensSmpSiz;
        usBeg           = XIO_ADC_ARRAY_SIZ - usSiz;
        siXIOCrossMac12 = SFGetMacAve(&ssXIOAdcArray1[usBeg],
                                      &ssXIOAdcArray2[usBeg], usSiz);
        siXIOCrossMac45 = SFGetMacAve(&ssXIOAdcArray4[usBeg],
                                      &ssXIOAdcArray5[usBeg], usSiz);
        siXIOCrossMac78 = SFGetMacAve(&ssXIOAdcArray7[usBeg],
                                      &ssXIOAdcArray8[usBeg], usSiz);
        ssDBmActPowerA  = SF_GET_ACT_PWR(siXIOCrossMac12, usDBpAmpGensVoltA,
                                         usDBpAmpGensCurrA, usDBpGensCtRatio);
        ssDBmActPowerB  = SF_GET_ACT_PWR(siXIOCrossMac45, usDBpAmpGensVoltB,
                                         usDBpAmpGensCurrB, usDBpGensCtRatio);
        ssDBmActPowerC  = SF_GET_ACT_PWR(siXIOCrossMac78, usDBpAmpGensVoltC,
                                         usDBpAmpGensCurrC, usDBpGensCtRatio);
        ssDBmActPowerAll = ssDBmActPowerA + ssDBmActPowerB + ssDBmActPowerC;
        /* ************************************************************ */
        /*                        Get Apparent Power                    */
        /* ************************************************************ */
        usDBmAppPowerA  = SF_GET_APP_PWR(usDBmGensVoltA, usDBmGensCurrA);
        usDBmAppPowerB  = SF_GET_APP_PWR(usDBmGensVoltB, usDBmGensCurrB);
        usDBmAppPowerC  = SF_GET_APP_PWR(usDBmGensVoltC, usDBmGensCurrC);
        usDBmAppPowerAll = usDBmAppPowerA + usDBmAppPowerB + usDBmAppPowerC;
        /* ************************************************************ */
        /*                        Get Reactive Power                    */
        /* ************************************************************ */
        ssDBmReactPowerA = SF_GET_REACT_PWR(usDBmAppPowerA, ssDBmActPowerA);
        ssDBmReactPowerB = SF_GET_REACT_PWR(usDBmAppPowerB, ssDBmActPowerB);
        ssDBmReactPowerC = SF_GET_REACT_PWR(usDBmAppPowerC, ssDBmActPowerC);
        ssDBmReactPowerAll = ssDBmReactPowerA + ssDBmReactPowerB + ssDBmReactPowerC;
        /* ************************************************************ */
        /*                        Get Power Factor                      */
        /* ************************************************************ */
        ssDBmPowerFactorA = SF_GET_PWR_FACT(ssDBmActPowerA, usDBmAppPowerA);
        ssDBmPowerFactorB = SF_GET_PWR_FACT(ssDBmActPowerB, usDBmAppPowerB);
        ssDBmPowerFactorC = SF_GET_PWR_FACT(ssDBmActPowerC, usDBmAppPowerC);
        ssDBmPowerFactorAll = SF_GET_PWR_FACT(ssDBmActPowerAll, usDBmAppPowerAll);
//        /* ************************************************************ */
//        /*              Read Speed, Switches, Keys, Analogs             */
//        /* ************************************************************ */
//        (void)SFSpdPulseRefrash(&sXIOSpdPulse0);
//        (void)SFSpdPulseRefrash(&sXIOSpdPulse1);
//        usDBmSpeedPickup1  = SFSpdPulseGetSpeed(&sXIOSpdPulse0);    
//        usDBmSpeedPickup2  = SFSpdPulseGetSpeed(&sXIOSpdPulse1);
//        if (usDBmSpeedPickup1 >= usDBmSpeedPickup2)
//        {   usDBmSpeed     = usDBmSpeedPickup1;
//        }   else
//        {   usDBmSpeed     = usDBmSpeedPickup2;
//        }
//        usDBmSwitchesInput = XIOReadSwitchesInput();        //开关量输入
//        usDBmBoardKeyInput = XIOReadBoardKeyInput();        //面板按键输入
//        (void)SFUpdateSwitchesStatus(usDBmSwitchesInput);   //开关量状态更新
//        (void)SFUpdateBoardKeyStatus(usDBmBoardKeyInput);   //面板按键状态更新
//        (void)SFUpdateAnalogStatus(&usDBmAdcInput[0]);      //输入模拟量更新
//        /* ************************************************************ */
//        /*                          Control Loop                        */
//        /* ************************************************************ */
//        (void)CTLSysMonitor();
//        (void)CTLSysController();
//        /* ************************************************************ */
//        /*                     Digital and PWM Outputs                  */
//        /* ************************************************************ */
//        (void)XIOUpdateSwitchesOutput(usDBmSwitchesOutput);    //输出端口
//        (void)XIOUpdateBoardLedOutput(usDBmBoardLedOutput);    //面板输出
//        (void)XIOUpdatePwmOutput(); 
//        (void)SFUpdataStatistics(usDBmSpeed,usDBmAppPowerAll);
//        uiDBhKwh32B += SFGetAccKwh(ssDBmActPowerAll);
//        uiDBhKvarh32B += SFGetAccKvarh(ssDBmReactPowerAll);
//        uiDBhRunTime32B += SFGetAccRunTime(usDBmEngineIsRunning);
//        (void)SFCheckToSaveHstry();
//        /* ************************************************************ */
//        /*                          If FFT Needs                        */
//        /* ************************************************************ */
//        usBeg = usDBmAdcFftChannel;
//        if ((usBeg <= 8) && (FFT_STS_GET_BIT(FFT_STS_BUFF_BUSY) == 0))
//        {   if (usBeg == 0)
//            {   pXIOFftDatBuf = &ssXIOAdcChDat0[0];
//            }   else if (usBeg == 1)
//            {   pXIOFftDatBuf = &ssXIOAdcChDat1[0];
//            }   else if (usBeg == 2)
//            {   pXIOFftDatBuf = &ssXIOAdcChDat2[0];
//            }   else if (usBeg == 3)
//            {   pXIOFftDatBuf = &ssXIOAdcChDat3[0];
//            }   else if (usBeg == 4)
//            {   pXIOFftDatBuf = &ssXIOAdcChDat4[0];
//            }   else if (usBeg == 5)
//            {   pXIOFftDatBuf = &ssXIOAdcChDat5[0];
//            }   else if (usBeg == 6)
//            {   pXIOFftDatBuf = &ssXIOAdcChDat6[0];
//            }   else if (usBeg == 7)
//            {   pXIOFftDatBuf = &ssXIOAdcChDat7[0];
//            }   else
//            {   pXIOFftDatBuf = &ssXIOAdcChDat8[0];
//            }
//            FFT_STS_SET_BIT(FFT_STS_BUFF_BUSY);
//            (void)SFCopy16s(pXIOFftDatBuf, ssFFTDatInput, FFT_FFT_DAT_SIZE);
//            (void)FFTPutCmdChar(FFT_CMD_DAT_RDY);
//        }
//        usXIOCalcTime = XIO_GET_FREE_TIMER() - usTim;
    }
}

/* ******************************************************************** */
/*                        XIODma1Ch1IntHook()                           */
/* ******************************************************************** */
void XIODma1Ch1IntHook (void)
{   DMA1_Channel1->CCR  &= ~DMA_CCR1_EN;       /* 1: Channel disabled   */
    DMA1_Channel1->CPAR  = (INT32U)(&(ADC1->DR));
    DMA1_Channel1->CMAR  = (INT32U)pXIOAdcDmaBuf;
    DMA1_Channel1->CNDTR =  XIO_ADC_DMA_BUF_SIZ;
    DMA1->IFCR           =  DMA_ISR_GIF1       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF1      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF1      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF1;     /* 1: clear TE flag      */
    DMA1_Channel1->CCR  |=  DMA_CCR1_EN;       /* 1: Channel enabled    */
    if (pXIOAdcDmaBuf   == &usXIOAdcDmaBuf0[0])
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf1[0];
    }   else
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf0[0];
    }
    (void)OSIntTaskResume(FW_TASK_PRIO_XIO);
}

/* ******************************************************************** */
/*                           XIOGetAdcChanDat()                         */
/* ******************************************************************** */
void XIOGetAdcChanDat (INT16U *pDmaBuf)
{   INT32U uiNumb, uiSize;
    INT16U *pData;
    pData  = pDmaBuf;
    uiNumb = 0;
    uiSize = XIO_ADC_SMPL_SIZ;
    while (uiSize--)
    {   ssXIOAdcChDat0[uiNumb]  = *pData++;
        ssXIOAdcChDat1[uiNumb]  = *pData++;
        ssXIOAdcChDat2[uiNumb]  = *pData++;
        ssXIOAdcChDat3[uiNumb]  = *pData++;
        ssXIOAdcChDat4[uiNumb]  = *pData++;
        ssXIOAdcChDat5[uiNumb]  = *pData++;
        ssXIOAdcChDat6[uiNumb]  = *pData++;
        ssXIOAdcChDat7[uiNumb]  = *pData++;
        ssXIOAdcChDat8[uiNumb]  = *pData++;
        ssXIOAdcChDat9[uiNumb]  = *pData++;
        ssXIOAdcChDat10[uiNumb] = *pData++;
        ssXIOAdcChDat11[uiNumb] = *pData++;
        ssXIOAdcChDat12[uiNumb] = *pData++;
        ssXIOAdcChDat13[uiNumb] = *pData++;
        ssXIOAdcChDat14[uiNumb] = *pData++;
        ssXIOAdcChDat15[uiNumb] = *pData++;
        uiNumb++;
    }
}

///* ******************************************************************** */
///*                        XIOReadSwitchesInput()                        */
///* ******************************************************************** */
//INT16U XIOReadSwitchesInput (void)
//{   
//    INT16U InputTemp=0;
//  
//    if(INPUT_VALUE_1 == 0)     {InputTemp |= 1<<XIO_PT_BT0;}        //开关量输入口1
//    if(INPUT_VALUE_2 == 0)     {InputTemp |= 1<<XIO_PT_BT1;}        //开关量输入口2

//    return InputTemp;
//}

///* ******************************************************************** */
///*                        XIOReadSwitchesInput()                        */
///* ******************************************************************** */
//#define Keymodle 0    //0-DBMeasure中按键不保存   1-DBMeasure中按键保存 
//#if(Keymodle)
//INT16U KeyTemp;
//#endif
//INT16U XIOReadBoardKeyInput (void)                                               //@@@@@@@@@@@@@@@@ZC
//{
//#if(!Keymodle)  
//    INT16U KeyTemp=0;
//#endif    
//    if(KEY_MODE_STOP == 0)     {KeyTemp |= 1<<SF_KEY_BIT_ENG_STOP;}        //停机键
//    if(KEY_MODE_MANUAL == 0)   {KeyTemp |= 1<<SF_KEY_BIT_MODE_MANUAL;}     //手动键
//    if(KEY_MODE_AUTO == 0)     {KeyTemp |= 1<<SF_KEY_BIT_MODE_AUTO;}       //自动键
//    if(KEY_MODE_RESET == 0)    {KeyTemp |= 1<<SF_KEY_BIT_ERROR_RSET;}      //复位键   
//    if(KEY_MODE_START == 0)    {KeyTemp |= 1<<SF_KEY_BIT_ENG_START;}       //起机键
//    if(KEY_MODE_DOWN == 0)     {KeyTemp |= 1<<SF_KEY_BIT_MENU_DOWN;}       //向下键
//    if(KEY_MODE_ENTER == 0)    {KeyTemp |= 1<<SF_KEY_BIT_MENU_ENTER;}      //确认键
//    if(KEY_MODE_UP == 0)       {KeyTemp |= 1<<SF_KEY_BIT_MENU_UP;}         //向上键  
//    return KeyTemp;
//}
///* ******************************************************************** */
///*                       XIO_SetState()                      */
///* ******************************************************************** */
//void XIO_SetState(GPIO_TypeDef *pPt,INT08U ucBit,u8 usSet)
//{    
//    if (usSet    ==  0)
//    {   pPt->BRR  = (INT32U)0x01 << ucBit;
//    }   else
//    {   pPt->BSRR = (INT32U)0x01 << ucBit;
//    }       
//}
///* ******************************************************************** */
///*                       XIOUpdateSwitchesOutput()                      */
///* ******************************************************************** */
//void XIOUpdateSwitchesOutput (INT16U usOutput)
//{
//    XIO_SetState(GPIOB, XIO_PT_BT8,(usOutput>>0)&0x1);      //输出口1 PB8   OUT1
//    XIO_SetState(GPIOB, XIO_PT_BT3,(usOutput>>1)&0x1);      //输出口2 PB3   OUT2    
//    XIO_SetState(GPIOB, XIO_PT_BT6,(usOutput>>2)&0x1);      //输出口3 PB6   OUT3
//    XIO_SetState(GPIOB, XIO_PT_BT7,(usOutput>>3)&0x1);      //输出口4 PB7   OUT4    
//    XIO_SetState(GPIOC, XIO_PT_BT5,(usOutput>>4)&0x1);      //输出口5 PC5   OUT5    
//    XIO_SetState(GPIOC, XIO_PT_BT4,(usOutput>>5)&0x1);      //输出口6 PC4   OUT6   
//    
////    XIO_SetState(GPIOB, XIO_PT_BT8,(usOutput>>6)&0x1);      //输出口7 PB8
////    XIO_SetState(GPIOB, XIO_PT_BT8,(usOutput>>7)&0x1);      //输出口8 PB8
////    XIO_SetState(GPIOB, XIO_PT_BT8,(usOutput>>8)&0x1);      //输出口9 PB8
////    XIO_SetState(GPIOB, XIO_PT_BT8,(usOutput>>9)&0x1);      //输出口10 PB8
////    XIO_SetState(GPIOB, XIO_PT_BT8,(usOutput>>10)&0x1);      //输出口11 PB8
////    XIO_SetState(GPIOB, XIO_PT_BT8,(usOutput>>11)&0x1);      //输出口12 PB8
////    XIO_SetState(GPIOB, XIO_PT_BT8,(usOutput>>12)&0x1);      //输出口13 PB8
////    XIO_SetState(GPIOB, XIO_PT_BT8,(usOutput>>13)&0x1);      //输出口14 PB8    
//    
//    XIO_SetState(GPIOA, XIO_PT_BT15,(usOutput>>14)&0x1);     //输出口15 PA15   CRANK  
//    XIO_SetState(GPIOB, XIO_PT_BT4,(usOutput>>15)&0x1);      //输出口16 PB4   D+  
//}

///* ******************************************************************** */
///*                       XIOUpdateBoardLedOutput()                      */
///* ******************************************************************** */
//void XIOUpdateBoardLedOutput (INT16U usOutput)
//{
//}

///* ******************************************************************** */
///*                           XIOInitDigInput()                          */
///* ******************************************************************** */
//void XIOInitDigInput (void)
//{                                                                      //按键端口初始化
//    XIOConfigGPIO(GPIOE, XIO_PT_BT6, XIO_PT_GPI_PULL, XIO_PT_SET_1);   //停机键 PE6
//    XIOConfigGPIO(GPIOE, XIO_PT_BT5, XIO_PT_GPI_PULL, XIO_PT_SET_1);   //手动键 PE5
//    XIOConfigGPIO(GPIOD, XIO_PT_BT3, XIO_PT_GPI_PULL, XIO_PT_SET_1);   //自动键 PD3
//    XIOConfigGPIO(GPIOC, XIO_PT_BT11, XIO_PT_GPI_PULL, XIO_PT_SET_1);  //复位键 PC11
//    XIOConfigGPIO(GPIOC, XIO_PT_BT10, XIO_PT_GPI_PULL, XIO_PT_SET_1);  //起机键 PC10
//    XIOConfigGPIO(GPIOB, XIO_PT_BT5, XIO_PT_GPI_PULL, XIO_PT_SET_1);   //向下键 PB5
//    XIOConfigGPIO(GPIOB, XIO_PT_BT12, XIO_PT_GPI_PULL, XIO_PT_SET_1);  //确认键 PB12
//    XIOConfigGPIO(GPIOB, XIO_PT_BT10, XIO_PT_GPI_PULL, XIO_PT_SET_1);  //向上键 PB10
// 
//                                                                          //输入端口初始化
//    XIOConfigGPIO(GPIOE, XIO_PT_BT2, XIO_PT_GPI_PULL, XIO_PT_SET_1);   //输入1 PE2
//    XIOConfigGPIO(GPIOE, XIO_PT_BT3, XIO_PT_GPI_PULL, XIO_PT_SET_1);   //输入2 PE3
//}

///* ******************************************************************** */
///*                           XIOInitDigOutput()                         */
///* ******************************************************************** */
//void XIOInitDigOutput (void)
//{
//    XIOConfigREMAP(AFIO_MAPR_SWJ_CFG_JTAGDISABLE,0);
//    
//    XIOConfigGPIO(GPIOB, XIO_PT_BT8, XIO_PT_GPO_PP_10M, XIO_PT_SET_0);   //输出口1 PB8  OUT1
//    XIOConfigGPIO(GPIOB, XIO_PT_BT3, XIO_PT_GPO_PP_10M, XIO_PT_SET_0);   //输出口2 PB3  OUT2
//    XIOConfigGPIO(GPIOB, XIO_PT_BT6, XIO_PT_GPO_PP_10M, XIO_PT_SET_0);   //输出口3 PB6  OUT3
//    XIOConfigGPIO(GPIOB, XIO_PT_BT7, XIO_PT_GPO_PP_10M, XIO_PT_SET_0);   //输出口4 PB7  OUT4
//    XIOConfigGPIO(GPIOC, XIO_PT_BT5, XIO_PT_GPO_PP_10M, XIO_PT_SET_0);   //输出口5 PC5  OUT5
//    XIOConfigGPIO(GPIOC, XIO_PT_BT4, XIO_PT_GPO_PP_10M, XIO_PT_SET_0);   //输出口6 PC4  OUT6
//    
////    XIOConfigGPIO(GPIOB, XIO_PT_BT8, XIO_PT_GPO_PP_10M, XIO_PT_SET_1);   //输出口7 PB8  OUT1
////    XIOConfigGPIO(GPIOB, XIO_PT_BT8, XIO_PT_GPO_PP_10M, XIO_PT_SET_1);   //输出口8 PB8  OUT1
////    XIOConfigGPIO(GPIOB, XIO_PT_BT8, XIO_PT_GPO_PP_10M, XIO_PT_SET_1);   //输出口9 PB8  OUT1
////    XIOConfigGPIO(GPIOB, XIO_PT_BT8, XIO_PT_GPO_PP_10M, XIO_PT_SET_1);   //输出口10 PB8  OUT1
////    XIOConfigGPIO(GPIOB, XIO_PT_BT8, XIO_PT_GPO_PP_10M, XIO_PT_SET_1);   //输出口11 PB8  OUT1
////    XIOConfigGPIO(GPIOB, XIO_PT_BT8, XIO_PT_GPO_PP_10M, XIO_PT_SET_1);   //输出口12 PB8  OUT1
////    XIOConfigGPIO(GPIOB, XIO_PT_BT8, XIO_PT_GPO_PP_10M, XIO_PT_SET_1);   //输出口13 PB8  OUT1
////    XIOConfigGPIO(GPIOB, XIO_PT_BT8, XIO_PT_GPO_PP_10M, XIO_PT_SET_1);   //输出口14 PB8  OUT1
//    
//    XIOConfigGPIO(GPIOA, XIO_PT_BT15, XIO_PT_GPO_PP_10M, XIO_PT_SET_0);   //输出口15 PA15  CRANK
//    XIOConfigGPIO(GPIOB, XIO_PT_BT4, XIO_PT_GPO_PP_10M, XIO_PT_SET_0);   //输出口16 PB4  D+   
//}

///* ******************************************************************** */
///*                         XIOUpdatePwmOutput()                         */
///* ******************************************************************** */
//void XIOUpdatePwmOutput (void)
//{   INT16U usD0;
//    /* ************************** PWM Output 1 ************************ */
//   #ifdef XIO_PWMOUT1_TIM4CH
//    usD0 = usDBpPWMOut1Assign;
//    if (usD0 < DB_MEASU_SIZE)
//    {   usD0 = aDBMeasu[usD0];
//        usD0 = SFInterp16u(usD0, usDBpPWMOut1RefLow,  usDBpPWMOut1RefHigh,
//                                 usDBpPWMOut1DutyLow, usDBpPWMOut1DutyHigh);
//        (void)XIOUpdateTim4PwmCh(XIO_PWMOUT1_TIM4CH, usDBpPWMOut1Period, usD0);
//    }
//    else
//    {   (void)XIOUpdateTim4PwmCh(XIO_PWMOUT1_TIM4CH, XIO_PWM_PERIOD_DEF, 0);
//    }
//   #endif
//    /* ************************** PWM Output 2 ************************ */
//   #ifdef XIO_PWMOUT2_TIM4CH
//    usD0 = usDBpPWMOut2Assign;
//    if (usD0 < DB_MEASU_SIZE)
//    {   usD0 = aDBMeasu[usD0];
//        usD0 = SFInterp16u(usD0, usDBpPWMOut2RefLow,  usDBpPWMOut2RefHigh,
//                                 usDBpPWMOut2DutyLow, usDBpPWMOut2DutyHigh);
//        (void)XIOUpdateTim4PwmCh(XIO_PWMOUT2_TIM4CH, usDBpPWMOut2Period, usD0);
//    }
//    else
//    {   (void)XIOUpdateTim4PwmCh(XIO_PWMOUT2_TIM4CH, XIO_PWM_PERIOD_DEF, 0);
//    }
//   #endif
//    /* ************************** PWM Output 3 ************************ */
//   #ifdef XIO_PWMOUT3_TIM4CH
//    usD0 = usDBpPWMOut3Assign;
//    if (usD0 < DB_MEASU_SIZE)
//    {   usD0 = aDBMeasu[usD0];
//        usD0 = SFInterp16u(usD0, usDBpPWMOut3RefLow,  usDBpPWMOut3RefHigh,
//                                 usDBpPWMOut3DutyLow, usDBpPWMOut3DutyHigh);
//        (void)XIOUpdateTim4PwmCh(XIO_PWMOUT3_TIM4CH, usDBpPWMOut3Period, usD0);
//    }
//    else
//    {   (void)XIOUpdateTim4PwmCh(XIO_PWMOUT3_TIM4CH, XIO_PWM_PERIOD_DEF, 0);
//    }
//   #endif
//    /* ************************** PWM Output 4 ************************ */
//   #ifdef XIO_PWMOUT4_TIM4CH
//    usD0 = usDBpPWMOut4Assign;
//    if (usD0 < DB_MEASU_SIZE)
//    {   usD0 = aDBMeasu[usD0];
//        usD0 = SFInterp16u(usD0, usDBpPWMOut4RefLow,  usDBpPWMOut4RefHigh,
//                                 usDBpPWMOut4DutyLow, usDBpPWMOut4DutyHigh);
//        (void)XIOUpdateTim4PwmCh(XIO_PWMOUT4_TIM4CH, usDBpPWMOut4Period, usD0);
//    }
//    else
//    {   (void)XIOUpdateTim4PwmCh(XIO_PWMOUT4_TIM4CH, XIO_PWM_PERIOD_DEF, 0);
//    }
//   #endif
//}

/* ******************************************************************** */
/*                              XIOInitADC1()                           */
/* ******************************************************************** */
void XIOInitADC1 (void)
{   XIOConfigGPIO(GPIOA, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT2, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT3, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT4, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT5, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT6, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT7, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT2, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT3, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
 //   XIOConfigGPIO(GPIOC, XIO_PT_BT4, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
 //   XIOConfigGPIO(GPIOC, XIO_PT_BT5, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    RCC->APB2ENR |=  RCC_APB2ENR_ADC1EN;       /* 1: ADC1 clock enable  */
    ADC1->CR1    &= ~ADC_CR1_EOCIE             /* EOC Interrupt disable */
                 &  ~ADC_CR1_AWDIE             /* Analog Watchdog inter */
                 &  ~ADC_CR1_JEOCIE            /* Injected chan interru */
                 &  ~ADC_CR1_SCAN              /* Scan mode disable     */
                 &  ~ADC_CR1_AWDSGL            /* Disnable the watchdog */
                 &  ~ADC_CR1_JAUTO             /* Injected group conver */
                 &  ~ADC_CR1_DISCEN            /* Discontinuous mode    */
                 &  ~ADC_CR1_JDISCEN;          /* Discontinuous mode    */
    ADC1->CR2    &= ~ADC_CR2_ADON              /* A/D Converter OFF     */
                 &  ~ADC_CR2_CONT              /* Continuous Conversion */
                 &  ~ADC_CR2_CAL               /* A/D Calibration       */
                 &  ~ADC_CR2_DMA               /* DMA mode disable      */
                 &  ~ADC_CR2_ALIGN             /* Data Alignment right  */
                 &  ~ADC_CR2_EXTSEL            /* EXTSEL[2:0]=0: T1_CC1 */
                 &  ~ADC_CR2_EXTTRIG;          /* EXT triger Disabled   */
    ADC1->SMPR2   = (XIO_ADC1_SMPL_CYC << 0)   /* Chan 0  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 3)   /* Chan 1  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 6)   /* Chan 2  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 9)   /* Chan 3  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 12)  /* Chan 4  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 15)  /* Chan 5  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 18)  /* Chan 6  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 21)  /* Chan 7  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 24)  /* Chan 8  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 27); /* Chan 9  Sample Cycles */
    ADC1->SMPR1   = (XIO_ADC1_SMPL_CYC << 0)   /* Chan 10 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 3)   /* Chan 11 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 6)   /* Chan 12 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 9)   /* Chan 13 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 12)  /* Chan 14 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 15)  /* Chan 15 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 18)  /* Chan 16 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 21); /* Chan 17 Sample Cycles */
    ADC1->SQR3    = (XIO_ADC1_CH_1ST  << 0)    /* 1st  Chan in sequence */
                 |  (XIO_ADC1_CH_2ND  << 5)    /* 2nd  Chan in sequence */
                 |  (XIO_ADC1_CH_3RD  << 10)   /* 3rd  Chan in sequence */
                 |  (XIO_ADC1_CH_4TH  << 15)   /* 4th  Chan in sequence */
                 |  (XIO_ADC1_CH_5TH  << 20)   /* 5th  Chan in sequence */
                 |  (XIO_ADC1_CH_6TH  << 25);  /* 6th  Chan in sequence */
    ADC1->SQR2    = (XIO_ADC1_CH_7TH  << 0)    /* 7th  Chan in sequence */
                 |  (XIO_ADC1_CH_8TH  << 5)    /* 8th  Chan in sequence */
                 |  (XIO_ADC1_CH_9TH  << 10)   /* 9th  Chan in sequence */
                 |  (XIO_ADC1_CH_10TH << 15)   /* 10th Chan in sequence */
                 |  (XIO_ADC1_CH_11TH << 20)   /* 11th Chan in sequence */
                 |  (XIO_ADC1_CH_12TH << 25);  /* 12th Chan in sequence */
    ADC1->SQR1    = (XIO_ADC1_CH_13TH << 0)    /* 13th Chan in sequence */
                 |  (XIO_ADC1_CH_14TH << 5)    /* 14th Chan in sequence */
                 |  (XIO_ADC1_CH_15TH << 10)   /* 15th Chan in sequence */
                 |  (XIO_ADC1_CH_16TH << 15)   /* 16th Chan in sequence */
                 | ((XIO_NUM_OF_ADC1-1)<<20);  /* Chan Size in sequence */
    ADC1->CR1    |=  ADC_CR1_SCAN;             /* Scan mode enable      */    //使用扫描模式
    ADC1->CR2    |=  ADC_CR2_EXTTRIG           /* EXT triger Enabled    */   //外部事件起动转化
                 |   ADC_CR2_DMA;              /* DMA mode Enable       */   //使用DMA模式-直接存储器访问模式
    ADC1->CR2    |=  ADC_CR2_ADON;             /* A/D Converter On      */  //开启ADC并启动转化  此处应为0->1为断电模式下唤醒ADC
    ADC1->CR2    |=  ADC_CR2_RSTCAL;           /* Reset Calibration     */  //初始化校准寄存器
    while((ADC1->CR2 & ADC_CR2_RSTCAL) != 0);  /* Wait for Calib reset  */ //初始化校准寄存器完成后，此位由硬件置0.
    ADC1->CR2    |=  ADC_CR2_CAL;              /* A/D Calibration       */  //A/D校准
    while((ADC1->CR2 & ADC_CR2_CAL) != 0);     /* Wait for Calibration  */ //A/D校准完成后，此位由硬件置0.
}

///* ******************************************************************** */
///*                              XIOInitADC2()                           */
///* ******************************************************************** */
//void XIOInitADC2 (void)
//{   RCC->APB2ENR |=  RCC_APB2ENR_ADC2EN;       /* 1: ADC2 clock enable  */
//    ADC2->CR1    &= ~ADC_CR1_EOCIE             /* EOC Interrupt disable */
//                 &  ~ADC_CR1_AWDIE             /* Analog Watchdog inter */
//                 &  ~ADC_CR1_JEOCIE            /* Injected chan interru */
//                 &  ~ADC_CR1_SCAN              /* Scan mode disable     */
//                 &  ~ADC_CR1_AWDSGL            /* Disnable the watchdog */
//                 &  ~ADC_CR1_JAUTO             /* Injected group conver */
//                 &  ~ADC_CR1_DISCEN            /* Discontinuous mode    */
//                 &  ~ADC_CR1_JDISCEN;          /* Discontinuous mode    */
//    ADC2->CR2    &= ~ADC_CR2_ADON              /* A/D Converter OFF     */
//                 &  ~ADC_CR2_CONT              /* Continuous Conversion */
//                 &  ~ADC_CR2_CAL               /* A/D Calibration       */
//                 &  ~ADC_CR2_DMA               /* DMA mode disable      */
//                 &  ~ADC_CR2_ALIGN             /* Data Alignment right  */
//                 &  ~ADC_CR2_EXTSEL            /* EXTSEL[2:0] Sources   */
//                 &  ~ADC_CR2_EXTTRIG;          /* EXT triger Disabled   */
//    ADC2->SMPR2   = (XIO_ADC2_SMPL_CYC << 0)   /* Chan 0  Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 3)   /* Chan 1  Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 6)   /* Chan 2  Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 9)   /* Chan 3  Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 12)  /* Chan 4  Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 15)  /* Chan 5  Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 18)  /* Chan 6  Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 21)  /* Chan 7  Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 24)  /* Chan 8  Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 27); /* Chan 9  Sample Cycles */
//    ADC2->SMPR1   = (XIO_ADC2_SMPL_CYC << 0)   /* Chan 10 Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 3)   /* Chan 11 Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 6)   /* Chan 12 Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 9)   /* Chan 13 Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 12)  /* Chan 14 Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 15)  /* Chan 15 Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 18)  /* Chan 16 Sample Cycles */
//                 |  (XIO_ADC2_SMPL_CYC << 21); /* Chan 17 Sample Cycles */
//    ADC2->SQR3    = (XIO_ADC2_CH_1ST  << 0)    /* 1st  Chan in sequence */
//                 |  (XIO_ADC2_CH_2ND  << 5)    /* 2nd  Chan in sequence */
//                 |  (XIO_ADC2_CH_3RD  << 10)   /* 3rd  Chan in sequence */
//                 |  (XIO_ADC2_CH_4TH  << 15)   /* 4th  Chan in sequence */
//                 |  (XIO_ADC2_CH_5TH  << 20)   /* 5th  Chan in sequence */
//                 |  (XIO_ADC2_CH_6TH  << 25);  /* 6th  Chan in sequence */
//    ADC2->SQR2    = (XIO_ADC2_CH_7TH  << 0)    /* 7th  Chan in sequence */
//                 |  (XIO_ADC2_CH_8TH  << 5)    /* 8th  Chan in sequence */
//                 |  (XIO_ADC2_CH_9TH  << 10)   /* 9th  Chan in sequence */
//                 |  (XIO_ADC2_CH_10TH << 15)   /* 10th Chan in sequence */
//                 |  (XIO_ADC2_CH_11TH << 20)   /* 11th Chan in sequence */
//                 |  (XIO_ADC2_CH_12TH << 25);  /* 12th Chan in sequence */
//    ADC2->SQR1    = (XIO_ADC2_CH_13TH << 0)    /* 13th Chan in sequence */
//                 |  (XIO_ADC2_CH_14TH << 5)    /* 14th Chan in sequence */
//                 |  (XIO_ADC2_CH_15TH << 10)   /* 15th Chan in sequence */
//                 |  (XIO_ADC2_CH_16TH << 15)   /* 16th Chan in sequence */
//                 | ((XIO_NUM_OF_ADC2-1)<<20);  /* Chan Size in sequence */
//    ADC2->CR1    |=  ADC_CR1_SCAN;             /* Scan mode enable      */
//    ADC2->CR2    |=  ADC_CR2_EXTSEL;           /* Triger=111: SWSTART   */
//    ADC2->CR2    |=  ADC_CR2_ADON;             /* A/D Converter On      */
//    ADC2->CR2    |=  ADC_CR2_RSTCAL;           /* Reset Calibration     */
//    while((ADC2->CR2 & ADC_CR2_RSTCAL) != 0);  /* Wait for Calib reset  */
//    ADC2->CR2    |=  ADC_CR2_CAL;              /* A/D Calibration       */
//    while((ADC2->CR2 & ADC_CR2_CAL) != 0);     /* Wait for Calibration  */
//}

///* ******************************************************************** */
///*                       XIOAdc2StartConversion()                       */
///* ******************************************************************** */
//void XIOAdc2StartConversion (void)
//{   ADC2->CR2   |= ADC_CR2_SWSTART
//                |  ADC_CR2_ADON;
//}

///* ******************************************************************** */
///*                         XIOAdc2ReadResult()                          */
///* ******************************************************************** */
//INT16U XIOAdc2ReadResult (void)
//{   return (ADC2->DR);
//}

/* ******************************************************************** */
/*                          XIOInitDma1Ch1Adc()                         */
/* ******************************************************************** */
void XIOInitDma1Ch1Adc (void)
{   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA clock enable   */
    DMA1_Channel1->CCR  &= ~DMA_CCR1_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR1_PL        /* 0: Priority low       */
                        &  ~DMA_CCR1_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR1_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR1_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR1_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR1_DIR       /* 0: Read from periphe  */
                        &  ~DMA_CCR1_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR1_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR1_TCIE;     /* 0: TC interrupt off   */
    DMA1_Channel1->CCR  |=  DMA_CCR1_MINC      /* Memory increment mode */
                        |   DMA_CCR1_MSIZE_0   /* 01: Memory size 16bit */
                        |   DMA_CCR1_PSIZE_0   /* 01: Peripheral siz 16 */
                        |   DMA_CCR1_PL_1;     /* 01: Priority High     */
    DMA1->IFCR           =  DMA_ISR_GIF1       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF1      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF1      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF1;     /* 1: clear TE flag      */
    DMA1_Channel1->CNDTR =  XIO_ADC_DMA_BUF_SIZ;
    DMA1_Channel1->CPAR  = (INT32U)&(ADC1->DR);
    DMA1_Channel1->CMAR  = (INT32U)pXIOAdcDmaBuf;
    DMA1_Channel1->CCR  |=  DMA_CCR1_TCIE
                        |   DMA_CCR1_EN;
    if (pXIOAdcDmaBuf   == &usXIOAdcDmaBuf0[0])
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf1[0];
    }   else
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf0[0];
    }
}

/* ******************************************************************** */
/*                             XIOInitTim1()                            */
/* ******************************************************************** */
void XIOInitTim1 (void)
{   RCC->APB2ENR  |=  RCC_APB2ENR_TIM1EN;    /* 1: TIM1 clock enable    */
    RCC->APB2RSTR |=  RCC_APB2RSTR_TIM1RST;  /* 1: TIM1 clock reset     */
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST;  /* 0: TIM1 reset stop      */
    TIM1->CR1      =  0;                     /* TIM1 control register 1 */
    TIM1->CR2      =  0;                     /* TIM1 control register 2 */
    TIM1->SMCR     =  0;                     /* TIM1 slave mode control */
    TIM1->DIER     =  0;                     /* TIM1 DMA/Interrupt en   */
    TIM1->SR       =  0;                     /* TIM1 status register    */
    TIM1->EGR      =  0;                     /* TIM1 event generation   */
    TIM1->CCMR1    =  0;                     /* Capture/compare mode 1  */
    TIM1->CCMR2    =  0;                     /* Capture/compare mode 2  */
    TIM1->CCER     =  0;                     /* Capture/compare enable  */
    TIM1->CNT      =  0;                     /* TIM1 counter            */
    TIM1->PSC      =  71;                    /* Prescaler: 72(1us)      */
    TIM1->ARR      =  0xFFFF;                /* TIM1 auto-reload        */
    TIM1->RCR      =  0;                     /* TIM1 control register 1 */
    TIM1->CCR1     =  0;                     /* Capture/compare reg 1   */
    TIM1->CCR2     =  0;                     /* Capture/compare reg 2   */
    TIM1->CCR3     =  0;                     /* Capture/compare reg 3   */
    TIM1->CCR4     =  0;                     /* Capture/compare reg 4   */
    TIM1->BDTR     =  0;                     /* break and dead-time     */
    TIM1->DCR      =  0;                     /* DMA control register    */
    TIM1->DMAR     =  0;                     /* DMA address for full tr */
}

/* ******************************************************************** */
/*                       XIOInitTim1AdcTriger()                         */
/* ******************************************************************** */
void XIOInitTim1AdcTriger (void)
{   TIM1->CCMR1   |=  TIM_CCMR1_OC1M_2       /* CH1: 110, PWM mode 1    */
                  |   TIM_CCMR1_OC1M_1;      /* (111: PWM mode 2)       */
    TIM1->ARR      =  XIO_ADC_SMPL_TIM_US-1; /* Pwm Period              */
    TIM1->CCR1     =  XIO_ADC_SMPL_TIM_US/2; /* Pwm Duty                */
    TIM1->CCER    |=  TIM_CCER_CC1E;         /* OC1 enable              */
    TIM1->EGR      =  TIM_EGR_UG;            /* UG: Update generation   */
    TIM1->BDTR    |=  TIM_BDTR_MOE;          /* TIM1 Outputs enabled    */
    TIM1->CR1     |=  TIM_CR1_CEN;           /* 1: Counter enabled      */
}

///* ******************************************************************** */
///*                         XIOInitTim2()                                */
///* ******************************************************************** */
//void XIOInitTim2 (void)
//{   RCC->APB1ENR  |=  RCC_APB1ENR_TIM2EN;    /* 1: TIM2 clock enable    */
//    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM2RST;  /* 1: TIM2 clock reset     */
//    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM2RST;  /* 0: TIM2 reset stop      */
//    TIM2->CR1      =  0;                     /* TIM2 control register 1 */
//    TIM2->CR2      =  0;                     /* TIM2 control register 2 */
//    TIM2->SMCR     =  0;                     /* TIM2 slave mode control */
//    TIM2->DIER     =  0;                     /* TIM2 DMA/Interrupt en   */
//    TIM2->SR       =  0;                     /* TIM2 status register    */
//    TIM2->EGR      =  0;                     /* TIM2 event generation   */
//    TIM2->CCMR1    =  0;                     /* Capture/compare mode 1  */
//    TIM2->CCMR2    =  0;                     /* Capture/compare mode 2  */
//    TIM2->CCER     =  0;                     /* Capture/compare enable  */
//    TIM2->CNT      =  0;                     /* TIM2 counter            */
//    TIM2->PSC      =  71;                    /* TIM2 prescaler          */
//    TIM2->ARR      =  0xFFFF;                /* TIM2 auto-reload        */
//    TIM2->RCR      =  0;                     /* TIM2 control register 1 */
//    TIM2->CCR1     =  0;                     /* Capture/compare reg 1   */
//    TIM2->CCR2     =  0;                     /* Capture/compare reg 2   */
//    TIM2->CCR3     =  0;                     /* Capture/compare reg 3   */
//    TIM2->CCR4     =  0;                     /* Capture/compare reg 4   */
//    TIM2->BDTR     =  0;                     /* break and dead-time     */
//    TIM2->DCR      =  0;                     /* DMA control register    */
//    TIM2->DMAR     =  0;                     /* DMA address for full tr */
//}

///* ******************************************************************** */
///*                         XIOInitTim3()                                */
///* ******************************************************************** */
//void XIOInitTim3 (void)
//{   RCC->APB1ENR  |=  RCC_APB1ENR_TIM3EN;    /* 1: TIM3 clock enable    */
//    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM3RST;  /* 1: TIM3 clock reset     */
//    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM3RST;  /* 0: TIM3 reset stop      */
//    TIM3->CR1      =  0;                     /* TIM3 control register 1 */
//    TIM3->CR2      =  0;                     /* TIM3 control register 2 */
//    TIM3->SMCR     =  0;                     /* TIM3 slave mode control */
//    TIM3->DIER     =  0;                     /* TIM3 DMA/Interrupt en   */
//    TIM3->SR       =  0;                     /* TIM3 status register    */
//    TIM3->EGR      =  0;                     /* TIM3 event generation   */
//    TIM3->CCMR1    =  0;                     /* Capture/compare mode 1  */
//    TIM3->CCMR2    =  0;                     /* Capture/compare mode 2  */
//    TIM3->CCER     =  0;                     /* Capture/compare enable  */
//    TIM3->CNT      =  0;                     /* TIM3 counter            */
//    TIM3->PSC      =  71;                    /* TIM3 prescaler          */
//    TIM3->ARR      =  0xFFFF;                /* TIM3 auto-reload        */
//    TIM3->RCR      =  0;                     /* TIM3 control register 1 */
//    TIM3->CCR1     =  0;                     /* Capture/compare reg 1   */
//    TIM3->CCR2     =  0;                     /* Capture/compare reg 2   */
//    TIM3->CCR3     =  0;                     /* Capture/compare reg 3   */
//    TIM3->CCR4     =  0;                     /* Capture/compare reg 4   */
//    TIM3->BDTR     =  0;                     /* break and dead-time     */
//    TIM3->DCR      =  0;                     /* DMA control register    */
//    TIM3->DMAR     =  0;                     /* DMA address for full tr */
//}

///* ******************************************************************** */
///*                         XIOInitTim3FrqIn()                           */
///* ******************************************************************** */
//void XIOInitTim3FrqIn (void)
//{   XIOConfigREMAP(XIO_TIM3_AFIO_REMAP1, XIO_TIM3_AFIO_REMAP2);
//    XIOConfigGPIO(GPIOC, XIO_PT_BT6, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
//    XIOConfigGPIO(GPIOC, XIO_PT_BT7, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
//    XIOConfigGPIO(GPIOC, XIO_PT_BT8, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
//    XIOConfigGPIO(GPIOC, XIO_PT_BT9, XIO_PT_GPI_FLOAT, XIO_PT_SET_0);
//    TIM3->CCMR1   |=  TIM_CCMR1_CC1S_0       /* 01: CC1 as input        */
//                  |   TIM_CCMR1_IC1F_0       /* 0011: fSAMPLING =       */
//                  |   TIM_CCMR1_IC1F_1       /* fCK_INT, N = 8          */
//                  |   TIM_CCMR1_CC2S_0       /* 01: CC2 as input        */
//                  |   TIM_CCMR1_IC2F_0       /* 0011: fSAMPLING =       */
//                  |   TIM_CCMR1_IC2F_1;      /* fCK_INT, N = 8          */
//    TIM3->CCMR2   |=  TIM_CCMR2_CC3S_0       /* 01: CC3 as input        */
//                  |   TIM_CCMR2_IC3F_0       /* 0011: fSAMPLING =       */
//                  |   TIM_CCMR2_IC3F_1       /* fCK_INT, N = 8          */
//                  |   TIM_CCMR2_CC4S_0       /* 01: CC4 as input        */
//                  |   TIM_CCMR2_IC4F_0       /* 0011: fSAMPLING =       */
//                  |   TIM_CCMR2_IC4F_1;      /* fCK_INT, N = 8          */
//    TIM3->CCER    |=  TIM_CCER_CC1E          /* IC1 enable              */
//                  |   TIM_CCER_CC2E          /* IC2 enable              */
//                  |   TIM_CCER_CC3E          /* IC3 enable              */
//                  |   TIM_CCER_CC4E;         /* IC4 enable              */
//    TIM3->DIER    |=  TIM_DIER_CC1IE         /* CC1 interrupt enable    */
//                  |   TIM_DIER_CC2IE         /* CC2 interrupt enable    */
//                  |   TIM_DIER_CC3IE         /* CC3 interrupt enable    */
//                  |   TIM_DIER_CC4IE;        /* CC4 interrupt enable    */
//    TIM3->SR      &= ~TIM_SR_CC1IF           /* Clr CC1 interrupt Flag  */
//                  &  ~TIM_SR_CC2IF           /* Clr CC2 interrupt Flag  */
//                  &  ~TIM_SR_CC3IF           /* Clr CC3 interrupt Flag  */
//                  &  ~TIM_SR_CC4IF;          /* Clr CC4 interrupt Flag  */
//    TIM3->CR1     |=  TIM_CR1_CEN;           /* 1: Counter enabled      */
//    TIM3->EGR      =  TIM_EGR_UG;            /* UG: Update generation   */
//}

///* ******************************************************************** */
///*                           XIOTim3IntHook()                           */
///* ******************************************************************** */
//void XIOTim3IntHook (void)
//{   INT16U usTimSr;
//    usTimSr = TIM3->SR;
//    if ((usTimSr & TIM_SR_CC1IF) != 0)
//    {   TIM3->SR &= ~TIM_SR_CC1IF;
//        SFSpdPulsePutTime(TIM3->CCR1, &sXIOSpdPulse0);
//    }
//    else if ((usTimSr & TIM_SR_CC2IF) != 0)
//    {   TIM3->SR &= ~TIM_SR_CC2IF;
//        SFSpdPulsePutTime(TIM3->CCR2, &sXIOSpdPulse1);
//    }
//    else if ((usTimSr & TIM_SR_CC3IF) != 0)
//    {   TIM3->SR &= ~TIM_SR_CC3IF;
//        SFHardFreqPutTime(TIM3->CCR3, &sXIOHardFreq0);
//    }
//    else if ((usTimSr & TIM_SR_CC4IF) != 0)
//    {   TIM3->SR &= ~TIM_SR_CC4IF;
//        SFHardFreqPutTime(TIM3->CCR4, &sXIOHardFreq1);
//    }
//}

///* ******************************************************************** */
///*                         XIOInitTim4()                                */
///* ******************************************************************** */
//void XIOInitTim4 (void)
//{   RCC->APB1ENR  |=  RCC_APB1ENR_TIM4EN;    /* 1: TIM4 clock enable    */
//    RCC->APB1RSTR |=  RCC_APB1RSTR_TIM4RST;  /* 1: TIM4 clock reset     */
//    RCC->APB1RSTR &= ~RCC_APB1RSTR_TIM4RST;  /* 0: TIM4 reset stop      */
//    TIM4->CR1      =  0;                     /* TIM4 control register 1 */
//    TIM4->CR2      =  0;                     /* TIM4 control register 2 */
//    TIM4->SMCR     =  0;                     /* TIM4 slave mode control */
//    TIM4->DIER     =  0;                     /* TIM4 DMA/Interrupt en   */
//    TIM4->SR       =  0;                     /* TIM4 status register    */
//    TIM4->EGR      =  0;                     /* TIM4 event generation   */
//    TIM4->CCMR1    =  0;                     /* Capture/compare mode 1  */
//    TIM4->CCMR2    =  0;                     /* Capture/compare mode 2  */
//    TIM4->CCER     =  0;                     /* Capture/compare enable  */
//    TIM4->CNT      =  0;                     /* TIM4 counter            */
//    TIM4->PSC      =  71;                    /* TIM4 prescaler          */
//    TIM4->ARR      =  0xFFFF;                /* TIM4 auto-reload        */
//    TIM4->RCR      =  0;                     /* TIM4 control register 1 */
//    TIM4->CCR1     =  0;                     /* Capture/compare reg 1   */
//    TIM4->CCR2     =  0;                     /* Capture/compare reg 2   */
//    TIM4->CCR3     =  0;                     /* Capture/compare reg 3   */
//    TIM4->CCR4     =  0;                     /* Capture/compare reg 4   */
//    TIM4->BDTR     =  0;                     /* break and dead-time     */
//    TIM4->DCR      =  0;                     /* DMA control register    */
//    TIM4->DMAR     =  0;                     /* DMA address for full tr */
//}

///* ******************************************************************** */
///*                         XIOInitTim4PwmOut()                          */
///* ******************************************************************** */
//void XIOInitTim4PwmOut (void)
//{   XIOConfigREMAP(XIO_TIM4_AFIO_REMAP1, XIO_TIM4_AFIO_REMAP2);
//    XIOConfigGPIO(GPIOD, XIO_PT_BT12, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
//    XIOConfigGPIO(GPIOD, XIO_PT_BT13, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
//    XIOInitTim4PwmCh(XIO_PWMOUT1_TIM4CH, 0);
//    XIOInitTim4PwmCh(XIO_PWMOUT2_TIM4CH, 0);
//}

///* ******************************************************************** */
///*                         XIOInitTim4PwmCh()                           */
///* ******************************************************************** */
//void XIOInitTim4PwmCh (INT08U ucChan, INT08U ucSet)
//{   TIM4->CR1 |= TIM_CR1_ARPE;
//    TIM4->ARR  = XIO_PWM_PERIOD_DEF;
//    if (ucChan == 1)
//    {   TIM4->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE;
//        TIM4->CCER  |= TIM_CCER_CC1E;
//        TIM4->SR    &= ~TIM_SR_CC1IF;
//        TIM4->CCR1   = ucSet == 0 ? 0 : XIO_PWM_PERIOD_DEF;
//    }
//    else if (ucChan == 2)
//    {   TIM4->CCMR1 |= TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2PE;
//        TIM4->CCER  |= TIM_CCER_CC2E;
//        TIM4->SR    &= ~TIM_SR_CC2IF;
//        TIM4->CCR2   = ucSet == 0 ? 0 : XIO_PWM_PERIOD_DEF;
//    }
//    else if (ucChan == 3)
//    {   TIM4->CCMR2 |= TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3PE;
//        TIM4->CCER  |= TIM_CCER_CC3E;
//        TIM4->SR    &= ~TIM_SR_CC3IF;
//        TIM4->CCR3   = ucSet == 0 ? 0 : XIO_PWM_PERIOD_DEF;
//    }
//    else if (ucChan == 4)
//    {   TIM4->CCMR2 |= TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE;
//        TIM4->CCER  |= TIM_CCER_CC4E;
//        TIM4->SR    &= ~TIM_SR_CC4IF;
//        TIM4->CCR4   = ucSet == 0 ? 0 : XIO_PWM_PERIOD_DEF;
//    }
//    TIM4->EGR  = TIM_EGR_UG;
//    while ((TIM4->EGR & TIM_EGR_UG) != 0);
//    TIM4->CR1 |= TIM_CR1_CEN;
//}

///* ******************************************************************** */
///*                         XIOUpdateTim4PwmCh()                         */
///* ******************************************************************** */
//void XIOUpdateTim4PwmCh (INT08U ucChan, INT16U usPeriod, INT16U usDuty)
//{   if (ucChan == 1)
//    {   if((TIM4->ARR != usPeriod) || (TIM4->CCR1 != usDuty))
//        {   TIM4->ARR  = usPeriod;
//            TIM4->CCR1 = usDuty;
//            TIM4->EGR  = TIM_EGR_UG;
//        }
//    }
//    else if (ucChan == 2)
//    {   if((TIM4->ARR != usPeriod) || (TIM4->CCR2 != usDuty))
//        {   TIM4->ARR  = usPeriod;
//            TIM4->CCR2 = usDuty;
//            TIM4->EGR  = TIM_EGR_UG;
//        }
//    }
//    else if (ucChan == 3)
//    {   if((TIM4->ARR != usPeriod) || (TIM4->CCR3 != usDuty))
//        {   TIM4->ARR  = usPeriod;
//            TIM4->CCR3 = usDuty;
//            TIM4->EGR  = TIM_EGR_UG;
//        }
//    }
//    else if (ucChan == 4)
//    {   if((TIM4->ARR != usPeriod) || (TIM4->CCR4 != usDuty))
//        {   TIM4->ARR  = usPeriod;
//            TIM4->CCR4 = usDuty;
//            TIM4->EGR  = TIM_EGR_UG;
//        }
//    }
//}

/* ******************************************************************** */
/*                           XIOResetGPIO()                             */
/* ******************************************************************** */
void XIOResetGPIO (GPIO_TypeDef *pPt)
{   if (pPt == GPIOA)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPAEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPARST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPARST;
    }   else if (pPt ==  GPIOB)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPBEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPBRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPBRST;
    }   else if (pPt ==  GPIOC)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPCEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPCRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPCRST;
    }   else if (pPt ==  GPIOD)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPDEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPDRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPDRST;
    }   else if (pPt ==  GPIOE)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPEEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPERST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPERST;
    }
   #ifdef RCC_APB2ENR_IOPFEN
    else if (pPt == GPIOF)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPFEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPFRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPFRST;
    }
   #endif
   #ifdef RCC_APB2ENR_IOPGEN
    else if (pPt == GPIOG)
    {   RCC->APB2ENR  |=  RCC_APB2ENR_IOPGEN;
        RCC->APB2RSTR |=  RCC_APB2RSTR_IOPGRST;
        RCC->APB2RSTR &= ~RCC_APB2RSTR_IOPGRST;
    }
   #endif
}

/* ******************************************************************** */
/*                           XIOConfigGPIO()                            */
/* ******************************************************************** */
void XIOConfigGPIO (GPIO_TypeDef *pPt, INT08U ucBit, INT32U uiMod, INT16U usSet)
{   if (pPt == GPIOA)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    }   else if (pPt == GPIOB)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    }   else if (pPt == GPIOC)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    }   else if (pPt == GPIOD)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
    }   else if (pPt == GPIOE)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
    }
   #ifdef RCC_APB2ENR_IOPFEN
    else if (pPt == GPIOF)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPFEN;
    }
   #endif
   #ifdef RCC_APB2ENR_IOPGEN
    else if (pPt == GPIOG)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPGEN;
    }
   #endif
    else
    {   return;
    }
    if (usSet    ==  0)
    {   pPt->BRR  = (INT32U)0x01 << ucBit;
    }   else
    {   pPt->BSRR = (INT32U)0x01 << ucBit;
    }
    uiMod        &= (INT32U)0x0F;
    ucBit        *=  4;
    if (ucBit    <=  31)
    {   pPt->CRL &= ~((INT32U)0x0F << ucBit);
        pPt->CRL |=  uiMod << ucBit;
    }   else if (ucBit <= 63)
    {   ucBit    -=  32;
        pPt->CRH &= ~((INT32U)0x0F << ucBit);
        pPt->CRH |=  uiMod << ucBit;
    }
}

/* ******************************************************************** */
/*                           XIOConfigAFIO()                            */
/* ******************************************************************** */
void XIOConfigAFIO (INT32U uiRemap)
{   INT32U uiTmp, uiReg;
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    if ((uiRemap & 0x80000000) != 0)
    {   uiReg  = AFIO->MAPR2;
    }   else
    {   uiReg  = AFIO->MAPR;
    }
    uiTmp = uiRemap & 0x0000FFFF;
    if ((uiRemap & 0x00300000) == 0x00300000)
    {   uiReg &= ~0x0F000000;
        AFIO->MAPR &= ~0x0F000000;
    }
    else if ((uiRemap & 0x00100000) != 0)
    {   uiReg &= ~((INT32U)0x03 << ((uiRemap >> 16) & 0x0F));
        uiReg |=  0x0F000000;
    }
    else
    {   uiReg &= ~(uiTmp << ((uiRemap >> 17) & 0x10));
        uiReg |=  0x0F000000;
    }
    uiReg |= (uiTmp << ((uiRemap >> 17) & 0x10));
    if ((uiRemap & 0x80000000) != 0)
    {   AFIO->MAPR2 = uiReg;
    }   else
    {   AFIO->MAPR  = uiReg;
    }
}

/* ******************************************************************** */
/*                           XIOConfigAFIO()                            */
/* ******************************************************************** */
void XIOConfigREMAP (INT32U uiRemap1, INT32U uiRemap2)
{   RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
    AFIO->MAPR   |= uiRemap1;
    AFIO->MAPR2  |= uiRemap2;
}

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
