#pragma once

#include "../../TMCStepper.h"

namespace TMC2160_n {
    using TMC2130_n::GCONF_i;
    using TMC2130_n::GSTAT_i;
    using TMC2130_n::IHOLD_IRUN_i;
    using TMC2130_n::TPOWERDOWN_i;
    using TMC2130_n::TSTEP_i;
    using TMC2130_n::TPWMTHRS_i;
    using TMC2130_n::TCOOLTHRS_i;
    using TMC2130_n::THIGH_i;
    using TMC2130_n::XDIRECT_i;
    using TMC2130_n::VDCMIN_i;
    using TMC2130_n::MSLUTSEL_i;
    using TMC2130_n::MSLUTSTART_i;
    using TMC2130_n::MSCNT_i;
    using TMC2130_n::MSCURACT_i;

    // 0x6C RW: CHOPCONF
    template<typename TYPE>
    struct CHOPCONF_i {
        struct CHOPCONF_t {
            constexpr static uint8_t address = 0x6C;
            union {
                uint32_t sr : 32;
                struct {
                    uint8_t toff : 4,     // 0..3
                            hstrt : 3,    // 4..6
                            hend : 4;     // 7..10
                    bool fd3 : 1,         // 11
                        disfdcc : 1,      // 12
                        : 1,              // 13
                        chm : 1;          // 14
                    uint8_t tbl : 2;      // 15..16
                    bool    : 1,          // 17
                            vhighfs : 1,  // 18
                            vhighchm : 1; // 19
                    uint8_t tpfd : 4,     // 20..23
                            mres : 4;     // 24..27
                    bool    intpol : 1,   // 28
                            dedge : 1,    // 29
                            diss2g : 1,   // 30
                            diss2vs : 1;  // 31
                };
            };
        };

        uint32_t CHOPCONF() {
            return static_cast<TYPE*>(this)->read(CHOPCONF_t::address);
        }
        void CHOPCONF(uint32_t input) {
            static_cast<TYPE*>(this)->write(CHOPCONF_t::address, input);
        }

        void toff(      uint8_t B ) { CHOPCONF_t r{ CHOPCONF() }; r.toff = B;       CHOPCONF(r.sr); }
        void hstrt(     uint8_t B ) { CHOPCONF_t r{ CHOPCONF() }; r.hstrt = B;      CHOPCONF(r.sr); }
        void hend(      uint8_t B ) { CHOPCONF_t r{ CHOPCONF() }; r.hend = B;       CHOPCONF(r.sr); }
        //void fd(      uint8_t B ) { CHOPCONF_t r{ CHOPCONF() }; r.fd = B;         CHOPCONF(r.sr); }
        void disfdcc(   bool    B ) { CHOPCONF_t r{ CHOPCONF() }; r.disfdcc = B;    CHOPCONF(r.sr); }
        void rndtf(     bool    B ) { CHOPCONF_t r{ CHOPCONF() }; r.rndtf = B;      CHOPCONF(r.sr); }
        void chm(       bool    B ) { CHOPCONF_t r{ CHOPCONF() }; r.chm = B;        CHOPCONF(r.sr); }
        void tbl(       uint8_t B ) { CHOPCONF_t r{ CHOPCONF() }; r.tbl = B;        CHOPCONF(r.sr); }
        void vsense(    bool    B ) { CHOPCONF_t r{ CHOPCONF() }; r.vsense = B;     CHOPCONF(r.sr); }
        void vhighfs(   bool    B ) { CHOPCONF_t r{ CHOPCONF() }; r.vhighfs = B;    CHOPCONF(r.sr); }
        void vhighchm(  bool    B ) { CHOPCONF_t r{ CHOPCONF() }; r.vhighchm = B;   CHOPCONF(r.sr); }
        void sync(      uint8_t B ) { CHOPCONF_t r{ CHOPCONF() }; r.sync = B;       CHOPCONF(r.sr); }
        void mres(      uint8_t B ) { CHOPCONF_t r{ CHOPCONF() }; r.mres = B;       CHOPCONF(r.sr); }
        void intpol(    bool    B ) { CHOPCONF_t r{ CHOPCONF() }; r.intpol = B;     CHOPCONF(r.sr); }
        void dedge(     bool    B ) { CHOPCONF_t r{ CHOPCONF() }; r.dedge = B;      CHOPCONF(r.sr); }
        void diss2g(    bool    B ) { CHOPCONF_t r{ CHOPCONF() }; r.diss2g = B;     CHOPCONF(r.sr); }

        uint8_t toff()      { return CHOPCONF_t{ CHOPCONF() }.toff;     }
        uint8_t hstrt()     { return CHOPCONF_t{ CHOPCONF() }.hstrt;    }
        uint8_t hend()      { return CHOPCONF_t{ CHOPCONF() }.hend;     }
        //uint8_t fd()      { return CHOPCONF_t{ CHOPCONF() }.fd;       }
        bool    disfdcc()   { return CHOPCONF_t{ CHOPCONF() }.disfdcc;  }
        bool    rndtf()     { return CHOPCONF_t{ CHOPCONF() }.rndtf;    }
        bool    chm()       { return CHOPCONF_t{ CHOPCONF() }.chm;      }
        uint8_t tbl()       { return CHOPCONF_t{ CHOPCONF() }.tbl;      }
        bool    vsense()    { return CHOPCONF_t{ CHOPCONF() }.vsense;   }
        bool    vhighfs()   { return CHOPCONF_t{ CHOPCONF() }.vhighfs;  }
        bool    vhighchm()  { return CHOPCONF_t{ CHOPCONF() }.vhighchm; }
        uint8_t sync()      { return CHOPCONF_t{ CHOPCONF() }.sync;     }
        uint8_t mres()      { return CHOPCONF_t{ CHOPCONF() }.mres;     }
        bool    intpol()    { return CHOPCONF_t{ CHOPCONF() }.intpol;   }
        bool    dedge()     { return CHOPCONF_t{ CHOPCONF() }.dedge;    }
        bool    diss2g()    { return CHOPCONF_t{ CHOPCONF() }.diss2g;   }
    };

    using TMC2130_n::COOLCONF_i;
    using TMC2130_n::DCCTRL_i;
    using TMC2130_n::DRV_STATUS_i;
    using TMC2130_n::ENCM_CTRL_i;
    using TMC2130_n::LOST_STEPS_i;

    // 0x04 R: IOIN
    template<typename TYPE>
    struct IOIN_i {
        #pragma pack(push, 1)
        struct IOIN_t {
            constexpr static uint8_t address = 0x04;
            union {
                uint32_t sr;
                struct {
                    bool refl_step : 1,
                         refr_dir : 1,
                         encb_dcen_cfg4 : 1,
                         enca_dcin_cfg5 : 1,
                         drv_enn : 1,
                         dco_cfg6 : 1,
                         : 2;
                    uint16_t : 16;
                    uint8_t version : 8;
                };
            };
        };
        #pragma pack(pop)
        
        uint32_t  IOIN() {
            return static_cast<TYPE*>(this)->read(IOIN_t::address);
        }
        bool    refl_step()      { return IOIN_t{ IOIN() }.refl_step; }
        bool    refr_dir()       { return IOIN_t{ IOIN() }.refr_dir; }
        bool    encb_dcen_cfg4() { return IOIN_t{ IOIN() }.encb_dcen_cfg4; }
        bool    enca_dcin_cfg5() { return IOIN_t{ IOIN() }.enca_dcin_cfg5; }
        bool    drv_enn()        { return IOIN_t{ IOIN() }.drv_enn; }
        bool    dco_cfg6()       { return IOIN_t{ IOIN() }.dco_cfg6; }
        uint8_t version()        { return IOIN_t{ IOIN() }.version; }
    };

    // 0x0B W: GLOBAL_SCALER
    template<typename TYPE>
    struct GLOBAL_SCALER_i {
        struct GLOBAL_SCALER_t {
            constexpr static uint8_t address = 0x0B;
            uint8_t sr;
        };

        uint8_t GLOBAL_SCALER() {
            return r.sr;
        }
        void GLOBAL_SCALER(uint8_t input) {
            r.sr = input;
            static_cast<TYPE*>(this)->write(r.address, r.sr);
        }
    protected:
        GLOBAL_SCALER_t r{};
    };

    // 0x0C R: OFFSET_READ
    template<typename TYPE>
    struct OFFSET_READ_i {

        struct OFFSET_READ_t {
            constexpr static uint8_t address = 0x0C;
        };

        uint16_t OFFSET_READ() {
            return static_cast<TYPE*>(this)->read(OFFSET_READ_t::address);
        }
    };

    // 0x71 R: PWM_SCALE
    template<typename TYPE>
    struct PWM_SCALE_i {
        #pragma pack(push, 1)
        struct PWM_SCALE_t {
            constexpr static uint8_t address = 0x71;
            union {
                uint32_t sr;
                struct {
                    uint8_t pwm_scale_sum : 8,
                            : 8;
                    uint16_t pwm_scale_auto : 9;
                };
            };
        };
        #pragma pack(pop)

        uint32_t PWM_SCALE() {
            return static_cast<TYPE*>(this)->read(PWM_SCALE_t::address);
        }
        uint8_t pwm_scale_sum()   { return PWM_SCALE_t{ PWM_SCALE() }.pwm_scale_sum; }
        uint16_t pwm_scale_auto() { return PWM_SCALE_t{ PWM_SCALE() }.pwm_scale_auto; }
    };

    // 0x09 W: SHORT_CONF
    template<typename TYPE>
    struct SHORT_CONF_i {
        #pragma pack(push, 1)
        struct SHORT_CONF_t {
            constexpr static uint8_t address = 0x09;
            union {
                uint32_t sr : 19;
                struct {
                    uint8_t s2vs_level  : 4,
                            : 4,
                            s2g_level   : 4,
                            : 4,
                            shortfilter : 2;
                    bool shortdelay : 1;
                };
            };
        };
        #pragma pack(pop)

        uint32_t SHORT_CONF() { return r.sr; }
        void SHORT_CONF(uint32_t input) {
            r.sr = input;
            static_cast<TYPE*>(this)->write(r.address, r.sr);
        }

        void s2vs_level(uint8_t B)  { r.s2vs_level;  SHORT_CONF(r.sr); }
        void s2g_level(uint8_t B)   { r.s2g_level;   SHORT_CONF(r.sr); }
        void shortfilter(uint8_t B) { r.shortfilter; SHORT_CONF(r.sr); }
        void shortdelay(bool B)     { r.shortdelay;  SHORT_CONF(r.sr); }
        uint8_t s2vs_level()        { return r.s2vs_level;  }
        uint8_t s2g_level()         { return r.s2g_level;   }
        uint8_t shortfilter()       { return r.shortfilter; }
        bool shortdelay()           { return r.shortdelay;  }
    protected:
        SHORT_CONF_t r{};
    };

    // 0x0A W: DRV_CONF
    template<typename TYPE>
    struct DRV_CONF_i {
        #pragma pack(push, 1)
        struct DRV_CONF_t {
            constexpr static uint8_t address = 0x0A;
            union {
                uint32_t sr : 22;
                struct {
                    uint8_t bbmtime : 5,
                            : 3,
                            bbmclks : 4,
                            : 4,
                            otselect : 2,
                            drvstrength : 2,
                            filt_isense : 2;
                };
            };
        };
        #pragma pack(pop)

        uint32_t DRV_CONF() { return r.sr; }
        void DRV_CONF(uint32_t input) {
            r.sr = input;
            static_cast<TYPE*>(this)->write(r.address, r.sr);
        }

        void bbmtime(uint8_t B)     { r.bbmtime = B;        DRV_CONF(r.sr); }
        void bbmclks(uint8_t B)     { r.bbmclks = B;        DRV_CONF(r.sr); }
        void otselect(uint8_t B)    { r.otselect = B;       DRV_CONF(r.sr); }
        void drvstrength(uint8_t B) { r.drvstrength = B;    DRV_CONF(r.sr); }
        void filt_isense(uint8_t B) { r.filt_isense = B;    DRV_CONF(r.sr); }
        uint8_t bbmtime()           { return r.bbmtime;     }
        uint8_t bbmclks()           { return r.bbmclks;     }
        uint8_t otselect()          { return r.otselect;    }
        uint8_t drvstrength()       { return r.drvstrength; }
        uint8_t filt_isense()       { return r.filt_isense; }
    protected:
        DRV_CONF_t r{};
    };

    // 0x70 W: PWMCONF
    template<typename TYPE>
    struct PWMCONF_i {
        #pragma pack(push, 1)
        struct PWMCONF_t {
            constexpr static uint8_t address = 0x70;
            union {
                uint32_t sr;
                struct {
                    uint8_t pwm_ofs : 8,
                            pwm_grad : 8,
                            pwm_freq : 2;
                    bool pwm_autoscale : 1,
                         pwm_autograd : 1;
                    uint8_t freewheel : 2,
                            : 2,
                            pwm_reg : 4,
                            pwm_lim : 4;
                };
            };
        };
        #pragma pack(pop)

        uint32_t PWMCONF() {
            return r.sr;
        }
        void PWMCONF(uint32_t input) {
            r.sr = input;
            static_cast<TYPE*>(this)->write(r.address, r.sr);
        }

        void pwm_ofs        ( uint8_t B ) { r.pwm_ofs = B;       PWMCONF(r.sr); }
        void pwm_grad       ( uint8_t B ) { r.pwm_grad = B;      PWMCONF(r.sr); }
        void pwm_freq       ( uint8_t B ) { r.pwm_freq = B;      PWMCONF(r.sr); }
        void pwm_autoscale  ( bool    B ) { r.pwm_autoscale = B; PWMCONF(r.sr); }
        void pwm_autograd   ( bool    B ) { r.pwm_autograd = B;  PWMCONF(r.sr); }
        void freewheel      ( uint8_t B ) { r.freewheel = B;     PWMCONF(r.sr); }
        void pwm_reg        ( uint8_t B ) { r.pwm_reg = B;       PWMCONF(r.sr); }
        void pwm_lim        ( uint8_t B ) { r.pwm_lim = B;       PWMCONF(r.sr); }

        uint8_t pwm_ofs()       { return r.pwm_ofs;      }
        uint8_t pwm_grad()      { return r.pwm_grad;     }
        uint8_t pwm_freq()      { return r.pwm_freq;     }
        bool    pwm_autoscale() { return r.pwm_autoscale;}
        bool    pwm_autograd()  { return r.pwm_autograd; }
        uint8_t freewheel()     { return r.freewheel;    }
        uint8_t pwm_reg()       { return r.pwm_reg;      }
        uint8_t pwm_lim()       { return r.pwm_lim;      }
    protected:
        PWMCONF_t r{};
    };
}
