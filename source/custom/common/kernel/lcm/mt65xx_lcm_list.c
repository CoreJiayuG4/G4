#include <lcm_drv.h>
extern LCM_DRIVER hx8394_lg47_truly_lcm_drv;
extern LCM_DRIVER nt35590_auo47_truly_lcm_drv;
extern LCM_DRIVER nt35590_hd720_dsi_vdo_truly_lcm_drv;
extern LCM_DRIVER ssd2075_hd720_dsi_vdo_truly_lcm_drv;

LCM_DRIVER* lcm_driver_list[] = 
{ 
#if defined(HX8394_LG47_TRULY)
	&hx8394_lg47_truly_lcm_drv,
#endif

#if (defined(NT35590_AUO47_TRULY) || defined(NT35590_AUO50_YKL) || defined(NT35590_AUO45_TRULY) || defined(NT35590_CMI50_SLS) || defined(NT35590_AUO50_LLONG))
	&nt35590_auo47_truly_lcm_drv,
#endif

#if defined(NT35590_HD720_DSI_VDO_TRULY)
	&nt35590_hd720_dsi_vdo_truly_lcm_drv, 
#endif

#if defined(SSD2075_HD720_DSI_VDO_TRULY)
	&ssd2075_hd720_dsi_vdo_truly_lcm_drv, 
#endif
};

#define LCM_COMPILE_ASSERT(condition) LCM_COMPILE_ASSERT_X(condition, __LINE__)
#define LCM_COMPILE_ASSERT_X(condition, line) LCM_COMPILE_ASSERT_XX(condition, line)
#define LCM_COMPILE_ASSERT_XX(condition, line) char assertion_failed_at_line_##line[(condition)?1:-1]

unsigned int lcm_count = sizeof(lcm_driver_list)/sizeof(LCM_DRIVER*);
//LCM_COMPILE_ASSERT(0 != sizeof(lcm_driver_list)/sizeof(LCM_DRIVER*));
