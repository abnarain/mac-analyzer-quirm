#ifndef _TD_UTILS_H_
#define _TD_UTILS_H_
#ifdef _ALLBSD_SOURCE
#include <machine/endian.h>
#elif __linux__
#include <endian.h>
#endif

#if defined(__APPLE__)
#include <libkern/OSByteOrder.h>
#define bswap_16 OSSwapInt16
#define bswap_32 OSSwapInt32
#define bswap_64 OSSwapInt64
#else
#include <byteswap.h>
#endif

#define IEEE802_11_TSTAMP_LEN           8
#define IEEE802_11_BCNINT_LEN           2
#define IEEE802_11_CAPINFO_LEN          2
#define IEEE802_11_LISTENINT_LEN        2
#define IEEE802_11_AP_LEN               6
#define HASHNAMESIZE 1024 
//4096
#define BUFSIZE 128

#define HT_CAP 45
#define HT_INFO  61
#define RSN_INFO  48
#define VENDOR_SPECIFIC 221


#define E_SSID          0
#define E_RATES         1
#define E_FH            2
#define E_DS            3
#define E_CF            4
#define E_TIM           5
#define E_IBSS          6
#define E_CHALLENGE     16


#define IEEE802_11_FC_LEN               2
#define IEEE802_11_DUR_LEN              2
#define IEEE802_11_DA_LEN               6
#define IEEE802_11_SA_LEN               6
#define IEEE802_11_BSSID_LEN            6
#define IEEE802_11_RA_LEN               6
#define IEEE802_11_TA_LEN               6
#define IEEE802_11_SEQ_LEN              2
#define IEEE802_11_CTL_LEN              2
#define IEEE802_11_IV_LEN               3
#define IEEE802_11_KID_LEN              1


extern unsigned char *snapend;
/* Lengths of beacon components. */
#define MGMT_HDRLEN     (IEEE802_11_FC_LEN+IEEE802_11_DUR_LEN+\
                         IEEE802_11_DA_LEN+IEEE802_11_SA_LEN+\
                         IEEE802_11_BSSID_LEN+IEEE802_11_SEQ_LEN)


#define TTEST2(var, l) (snapend - (l) <= snapend && \
			(const u_char *)&(var) <= snapend - (l))


#define CAPABILITY_ESS(cap)     ((cap) & 0x0001)
#define CAPABILITY_IBSS(cap)    ((cap) & 0x0002)
#define CAPABILITY_CFP(cap)     ((cap) & 0x0004)
#define CAPABILITY_CFP_REQ(cap) ((cap) & 0x0008)
#define CAPABILITY_PRIVACY(cap) ((cap) & 0x0010)

#define FC_TO_DS(fc)            ((fc) & 0x0100)
#define FC_FROM_DS(fc)          ((fc) & 0x0200)
#define FC_MORE_FLAG(fc)        ((fc) & 0x0400)
#define FC_RETRY(fc)            ((fc) & 0x0800)
#define FC_POWER_MGMT(fc)       ((fc) & 0x1000)
#define FC_MORE_DATA(fc)        ((fc) & 0x2000)
#define FC_WEP(fc)              ((fc) & 0x4000)
#define FC_ORDER(fc)            ((fc) & 0x8000)
#define FC_TYPE(fc)             (((fc) >> 2) & 0x3)
#define FC_SUBTYPE(fc)          (((fc) >> 4) & 0xF)


#define IEEE80211_CHAN_FHSS \
        (IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_GFSK)
#define IEEE80211_CHAN_A \
        (IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM)
#define IEEE80211_CHAN_B \
        (IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_CCK)
#define IEEE80211_CHAN_PUREG \
        (IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_OFDM)
#define IEEE80211_CHAN_G \
        (IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_DYN)

#define IS_CHAN_FHSS(flags) \
        ((flags & IEEE80211_CHAN_FHSS) == IEEE80211_CHAN_FHSS)
#define IS_CHAN_A(flags) \
        ((flags & IEEE80211_CHAN_A) == IEEE80211_CHAN_A)
#define IS_CHAN_B(flags) \
        ((flags & IEEE80211_CHAN_B) == IEEE80211_CHAN_B)
#define IS_CHAN_PUREG(flags) \
        ((flags & IEEE80211_CHAN_PUREG) == IEEE80211_CHAN_PUREG)
#define IS_CHAN_G(flags) \
        ((flags & IEEE80211_CHAN_G) == IEEE80211_CHAN_G)
#define IS_CHAN_ANYG(flags) \
        (IS_CHAN_PUREG(flags) || IS_CHAN_G(flags))



/*
 * Macros to extract possibly-unaligned little-endian integral values.
 * XXX - do loads on little-endian machines that support unaligned loads?
 */
#define EXTRACT_LE_8BITS(p) (*(p))
#define EXTRACT_LE_16BITS(p) \
        ((u_int16_t)((u_int16_t)*((const u_int8_t *)(p) + 1) << 8 | \
                     (u_int16_t)*((const u_int8_t *)(p) + 0)))
#define EXTRACT_LE_32BITS(p) \
        ((u_int32_t)((u_int32_t)*((const u_int8_t *)(p) + 3) << 24 | \
                     (u_int32_t)*((const u_int8_t *)(p) + 2) << 16 | \
                     (u_int32_t)*((const u_int8_t *)(p) + 1) << 8 | \
                     (u_int32_t)*((const u_int8_t *)(p) + 0)))
#define EXTRACT_LE_24BITS(p) \
        ((u_int32_t)((u_int32_t)*((const u_int8_t *)(p) + 2) << 16 | \
                     (u_int32_t)*((const u_int8_t *)(p) + 1) << 8 | \
                     (u_int32_t)*((const u_int8_t *)(p) + 0)))
#define EXTRACT_LE_64BITS(p) \
        ((u_int64_t)((u_int64_t)*((const u_int8_t *)(p) + 7) << 56 | \
                     (u_int64_t)*((const u_int8_t *)(p) + 6) << 48 | \
                     (u_int64_t)*((const u_int8_t *)(p) + 5) << 40 | \
                     (u_int64_t)*((const u_int8_t *)(p) + 4) << 32 | \
                     (u_int64_t)*((const u_int8_t *)(p) + 3) << 24 | \
                     (u_int64_t)*((const u_int8_t *)(p) + 2) << 16 | \
                     (u_int64_t)*((const u_int8_t *)(p) + 1) << 8 | \
                     (u_int64_t)*((const u_int8_t *)(p) + 0)))



#ifndef roundup2
#define roundup2(x, y)  (((x)+((y)-1))&(~((y)-1))) /* if y is powers of two */
#endif

static const int ieee80211_htrates[16] = {
  13,             /* IFM_IEEE80211_MCS0 */
  26,             /* IFM_IEEE80211_MCS1 */
  39,             /* IFM_IEEE80211_MCS2 */
  52,             /* IFM_IEEE80211_MCS3 */
  78,             /* IFM_IEEE80211_MCS4 */
  104,            /* IFM_IEEE80211_MCS5 */
  117,            /* IFM_IEEE80211_MCS6 */
  130,            /* IFM_IEEE80211_MCS7 */
  26,             /* IFM_IEEE80211_MCS8 */
  52,             /* IFM_IEEE80211_MCS9 */
  78,             /* IFM_IEEE80211_MCS10 */
  104,            /* IFM_IEEE80211_MCS11 */
  156,            /* IFM_IEEE80211_MCS12 */
  208,            /* IFM_IEEE80211_MCS13 */
  234,            /* IFM_IEEE80211_MCS14 */
  260,            /* IFM_IEEE80211_MCS15 */
};


#define FC_TO_DS(fc)            ((fc) & 0x0100)
#define FC_FROM_DS(fc)          ((fc) & 0x0200)

#define FCF_FLAGS(x)           (((x) & 0xFF00) >> 8)

#define MGT_FRAME            0x0  /* Frame type is management */
#define CONTROL_FRAME        0x1  /* Frame type is control */
#define DATA_FRAME           0x2  /* Frame type is Data */


#define DATA_SHORT_HDR_LEN     24
#define DATA_LONG_HDR_LEN      30
#define MGT_FRAME_HDR_LEN      24  /* Length of Managment frame-headers */

#define FLAG_ORDER            0x80

#define DATA_FRAME_IS_NULL(x)  ((x) & 0x04)
#define DATA_FRAME_IS_QOS(x)     ((x) & 0x08)
#define IS_STRICTLY_ORDERED(x) ((x) & FLAG_ORDER)



#define DATA_ADDR_T1         0
#define DATA_ADDR_T2         (FLAG_FROM_DS << 8)
#define DATA_ADDR_T3         (FLAG_TO_DS << 8)
#define DATA_ADDR_T4         ((FLAG_TO_DS|FLAG_FROM_DS) << 8)

#define ST_ASSOC_REQUEST        0x0
#define ST_ASSOC_RESPONSE       0x1
#define ST_REASSOC_REQUEST      0x2
#define ST_REASSOC_RESPONSE     0x3
#define ST_PROBE_REQUEST        0x4
#define ST_PROBE_RESPONSE       0x5
/* RESERVED                     0x6  */
/* RESERVED                     0x7  */
#define ST_BEACON               0x8
#define ST_ATIM                 0x9
#define ST_DISASSOC             0xA
#define ST_AUTH                 0xB
#define ST_DEAUTH               0xC
#define ST_ACTION               0xD
/* RESERVED                     0xE  */
/* RESERVED                     0xF  */


#define CTRL_CONTROL_WRAPPER    0x7
#define CTRL_BAR        0x8
#define CTRL_BA         0x9
#define CTRL_PS_POLL    0xA
#define CTRL_RTS        0xB
#define CTRL_CTS        0xC
#define CTRL_ACK        0xD
#define CTRL_CF_END     0xE
#define CTRL_END_ACK    0xF

#define DATA_DATA                       0x0
#define DATA_DATA_CF_ACK                0x1
#define DATA_DATA_CF_POLL               0x2
#define DATA_DATA_CF_ACK_POLL           0x3
#define DATA_QOS_NODATA                 0xC
#define DATA_QOS_CF_POLL_NODATA         0xE
#define DATA_QOS_CF_ACK_POLL_NODATA     0xF
typedef unsigned char      uchar;



#define IEEE80211_CHAN_TURBO    0x0010  /* Turbo channel */
#define IEEE80211_CHAN_CCK      0x0020  /* CCK channel */
#define IEEE80211_CHAN_OFDM     0x0040  /* OFDM channel */
#define IEEE80211_CHAN_2GHZ     0x0080  /* 2 GHz spectrum channel. */
#define IEEE80211_CHAN_5GHZ     0x0100  /* 5 GHz spectrum channel */
#define IEEE80211_CHAN_PASSIVE  0x0200  /* Only passive scan allowed */
#define IEEE80211_CHAN_DYN      0x0400  /* Dynamic CCK-OFDM channel */
#define IEEE80211_CHAN_GFSK     0x0800  /* GFSK channel (FHSS PHY) */

#define IEEE80211_CHAN_STURBO   0x02000 /* 11a static turbo channel only */
#define IEEE80211_CHAN_HALF     0x04000 /* Half rate channel */
#define IEEE80211_CHAN_QUARTER  0x08000 /* Quarter rate channel */
#define IEEE80211_CHAN_HT20     0x10000 /* HT 20 channel */
#define IEEE80211_CHAN_HT40U    0x20000 /* HT 40 channel w/ ext above */
#define IEEE80211_CHAN_HT40D    0x40000 /* HT 40 channel w/ ext below */

#define MAX_MCS_INDEX   76

/*
 * Indices are:
 *
 *      the MCS index (0-76);
 *
 *      0 for 20 MHz, 1 for 40 MHz;
 *
 *      0 for a long guard interval, 1 for a short guard interval.
 */
static const float ieee80211_float_htrates[MAX_MCS_INDEX+1][2][2] = {
  /* MCS  0  */
  {       /* 20 Mhz */ {    6.5f,         /* SGI */    7.2f, },
	  /* 40 Mhz */ {   13.5f,         /* SGI */   15.0f, },
  },

  /* MCS  1  */
  {       /* 20 Mhz */ {   13.0f,         /* SGI */   14.4f, },
	  /* 40 Mhz */ {   27.0f,         /* SGI */   30.0f, },
  },

  /* MCS  2  */
  {       /* 20 Mhz */ {   19.5f,         /* SGI */   21.7f, },
	  /* 40 Mhz */ {   40.5f,         /* SGI */   45.0f, },
  },

  /* MCS  3  */
  {       /* 20 Mhz */ {   26.0f,         /* SGI */   28.9f, },
	  /* 40 Mhz */ {   54.0f,         /* SGI */   60.0f, },
  },

  /* MCS  4  */
  {       /* 20 Mhz */ {   39.0f,         /* SGI */   43.3f, },
	  /* 40 Mhz */ {   81.0f,         /* SGI */   90.0f, },
  },

  /* MCS  5  */
  {       /* 20 Mhz */ {   52.0f,         /* SGI */   57.8f, },
	  /* 40 Mhz */ {  108.0f,         /* SGI */  120.0f, },
  },

  /* MCS  6  */
  {       /* 20 Mhz */ {   58.5f,         /* SGI */   65.0f, },
	  /* 40 Mhz */ {  121.5f,         /* SGI */  135.0f, },
  },

  /* MCS  7  */
  {       /* 20 Mhz */ {   65.0f,         /* SGI */   72.2f, },
	  /* 40 Mhz */ {   135.0f,        /* SGI */  150.0f, },
  },

  /* MCS  8  */
  {       /* 20 Mhz */ {   13.0f,         /* SGI */   14.4f, },
	  /* 40 Mhz */ {   27.0f,         /* SGI */   30.0f, },
  },

  /* MCS  9  */
  {       /* 20 Mhz */ {   26.0f,         /* SGI */   28.9f, },
	  /* 40 Mhz */ {   54.0f,         /* SGI */   60.0f, },
  },

  /* MCS 10  */
  {       /* 20 Mhz */ {   39.0f,         /* SGI */   43.3f, },
	  /* 40 Mhz */ {   81.0f,         /* SGI */   90.0f, },
  },

  /* MCS 11  */
  {       /* 20 Mhz */ {   52.0f,         /* SGI */   57.8f, },
	  /* 40 Mhz */ {  108.0f,         /* SGI */  120.0f, },
  },

  /* MCS 12  */
  {       /* 20 Mhz */ {   78.0f,         /* SGI */   86.7f, },
	  /* 40 Mhz */ {  162.0f,         /* SGI */  180.0f, },
  },

  /* MCS 13  */
  {       /* 20 Mhz */ {  104.0f,         /* SGI */  115.6f, },
	  /* 40 Mhz */ {  216.0f,         /* SGI */  240.0f, },
  },

  /* MCS 14  */
  {       /* 20 Mhz */ {  117.0f,         /* SGI */  130.0f, },
	  /* 40 Mhz */ {  243.0f,         /* SGI */  270.0f, },
  },

  /* MCS 15  */
  {       /* 20 Mhz */ {  130.0f,         /* SGI */  144.4f, },
	  /* 40 Mhz */ {  270.0f,         /* SGI */  300.0f, },
  },
  /* MCS 16  */
  {       /* 20 Mhz */ {   19.5f,         /* SGI */   21.7f, },
	  /* 40 Mhz */ {   40.5f,         /* SGI */   45.0f, },
  },

  /* MCS 17  */
  {       /* 20 Mhz */ {   39.0f,         /* SGI */   43.3f, },
	  /* 40 Mhz */ {   81.0f,         /* SGI */   90.0f, },
  },

  /* MCS 18  */
  {       /* 20 Mhz */ {   58.5f,         /* SGI */   65.0f, },
	  /* 40 Mhz */ {  121.5f,         /* SGI */  135.0f, },
  },

  /* MCS 19  */
  {       /* 20 Mhz */ {   78.0f,         /* SGI */   86.7f, },
	  /* 40 Mhz */ {  162.0f,         /* SGI */  180.0f, },
  },

  /* MCS 20  */
  {       /* 20 Mhz */ {  117.0f,         /* SGI */  130.0f, },
	  /* 40 Mhz */ {  243.0f,         /* SGI */  270.0f, },
  },

  /* MCS 21  */
  {       /* 20 Mhz */ {  156.0f,         /* SGI */  173.3f, },
	  /* 40 Mhz */ {  324.0f,         /* SGI */  360.0f, },
  },

  /* MCS 22  */
  {       /* 20 Mhz */ {  175.5f,         /* SGI */  195.0f, },
	  /* 40 Mhz */ {  364.5f,         /* SGI */  405.0f, },
  },

  /* MCS 23  */
  {       /* 20 Mhz */ {  195.0f,         /* SGI */  216.7f, },
	  /* 40 Mhz */ {  405.0f,         /* SGI */  450.0f, },
  },

  /* MCS 24  */
  {       /* 20 Mhz */ {   26.0f,         /* SGI */   28.9f, },
	  /* 40 Mhz */ {   54.0f,         /* SGI */   60.0f, },
  },

  /* MCS 25  */
  {       /* 20 Mhz */ {   52.0f,         /* SGI */   57.8f, },
	  /* 40 Mhz */ {  108.0f,         /* SGI */  120.0f, },
  },
  /* MCS 26  */
  {       /* 20 Mhz */ {   78.0f,         /* SGI */   86.7f, },
	  /* 40 Mhz */ {  162.0f,         /* SGI */  180.0f, },
  },

  /* MCS 27  */
  {       /* 20 Mhz */ {  104.0f,         /* SGI */  115.6f, },
	  /* 40 Mhz */ {  216.0f,         /* SGI */  240.0f, },
  },

  /* MCS 28  */
  {       /* 20 Mhz */ {  156.0f,         /* SGI */  173.3f, },
	  /* 40 Mhz */ {  324.0f,         /* SGI */  360.0f, },
  },

  /* MCS 29  */
  {       /* 20 Mhz */ {  208.0f,         /* SGI */  231.1f, },
	  /* 40 Mhz */ {  432.0f,         /* SGI */  480.0f, },
  },

  /* MCS 30  */
  {       /* 20 Mhz */ {  234.0f,         /* SGI */  260.0f, },
	  /* 40 Mhz */ {  486.0f,         /* SGI */  540.0f, },
  },

  /* MCS 31  */
  {       /* 20 Mhz */ {  260.0f,         /* SGI */  288.9f, },
	  /* 40 Mhz */ {  540.0f,         /* SGI */  600.0f, },
  },

  /* MCS 32  */
  {       /* 20 Mhz */ {    0.0f,         /* SGI */    0.0f, }, /* not valid */
	  /* 40 Mhz */ {    6.0f,         /* SGI */    6.7f, },
  },

  /* MCS 33  */
  {       /* 20 Mhz */ {   39.0f,         /* SGI */   43.3f, },
	  /* 40 Mhz */ {   81.0f,         /* SGI */   90.0f, },
  },

  /* MCS 34  */
  {       /* 20 Mhz */ {   52.0f,         /* SGI */   57.8f, },
	  /* 40 Mhz */ {  108.0f,         /* SGI */  120.0f, },
  },

  /* MCS 35  */
  {       /* 20 Mhz */ {   65.0f,         /* SGI */   72.2f, },
	  /* 40 Mhz */ {  135.0f,         /* SGI */  150.0f, },
  },

  /* MCS 36  */
  {       /* 20 Mhz */ {   58.5f,         /* SGI */   65.0f, },
	  /* 40 Mhz */ {  121.5f,         /* SGI */  135.0f, },
  },

  /* MCS 37  */
  {       /* 20 Mhz */ {   78.0f,         /* SGI */   86.7f, },
	  /* 40 Mhz */ {  162.0f,         /* SGI */  180.0f, },
  },

  /* MCS 38  */
  {       /* 20 Mhz */ {   97.5f,         /* SGI */  108.3f, },
	  /* 40 Mhz */ {  202.5f,         /* SGI */  225.0f, },
  },

  /* MCS 39  */
  {       /* 20 Mhz */ {   52.0f,         /* SGI */   57.8f, },
	  /* 40 Mhz */ {  108.0f,         /* SGI */  120.0f, },
  },

  /* MCS 40  */
  {       /* 20 Mhz */ {   65.0f,         /* SGI */   72.2f, },
	  /* 40 Mhz */ {  135.0f,         /* SGI */  150.0f, },
  },

  /* MCS 41  */
  {       /* 20 Mhz */ {   65.0f,         /* SGI */   72.2f, },
	  /* 40 Mhz */ {  135.0f,         /* SGI */  150.0f, },
  },

  /* MCS 42  */
  {       /* 20 Mhz */ {   78.0f,         /* SGI */   86.7f, },
	  /* 40 Mhz */ {  162.0f,         /* SGI */  180.0f, },
  },

  /* MCS 43  */
  {       /* 20 Mhz */ {   91.0f,         /* SGI */  101.1f, },
	  /* 40 Mhz */ {  189.0f,         /* SGI */  210.0f, },
  },

  /* MCS 44  */
  {       /* 20 Mhz */ {   91.0f,         /* SGI */  101.1f, },
	  /* 40 Mhz */ {  189.0f,         /* SGI */  210.0f, },
  },

  /* MCS 45  */
  {       /* 20 Mhz */ {  104.0f,         /* SGI */  115.6f, },
	  /* 40 Mhz */ {  216.0f,         /* SGI */  240.0f, },
  },
  /* MCS 46  */
  {       /* 20 Mhz */ {   78.0f,         /* SGI */   86.7f, },
	  /* 40 Mhz */ {  162.0f,         /* SGI */  180.0f, },
  },

  /* MCS 47  */
  {       /* 20 Mhz */ {   97.5f,         /* SGI */  108.3f, },
	  /* 40 Mhz */ {  202.5f,         /* SGI */  225.0f, },
  },

  /* MCS 48  */
  {       /* 20 Mhz */ {   97.5f,         /* SGI */  108.3f, },
	  /* 40 Mhz */ {  202.5f,         /* SGI */  225.0f, },
  },

  /* MCS 49  */
  {       /* 20 Mhz */ {  117.0f,         /* SGI */  130.0f, },
	  /* 40 Mhz */ {  243.0f,         /* SGI */  270.0f, },
  },

  /* MCS 50  */
  {       /* 20 Mhz */ {  136.5f,         /* SGI */  151.7f, },
	  /* 40 Mhz */ {  283.5f,         /* SGI */  315.0f, },
  },

  /* MCS 51  */
  {       /* 20 Mhz */ {  136.5f,         /* SGI */  151.7f, },
	  /* 40 Mhz */ {  283.5f,         /* SGI */  315.0f, },
  },

  /* MCS 52  */
  {       /* 20 Mhz */ {  156.0f,         /* SGI */  173.3f, },
	  /* 40 Mhz */ {  324.0f,         /* SGI */  360.0f, },
  },

  /* MCS 53  */
  {       /* 20 Mhz */ {   65.0f,         /* SGI */   72.2f, },
	  /* 40 Mhz */ {  135.0f,         /* SGI */  150.0f, },
  },

  /* MCS 54  */
  {       /* 20 Mhz */ {   78.0f,         /* SGI */   86.7f, },
	  /* 40 Mhz */ {  162.0f,         /* SGI */  180.0f, },
  },

  /* MCS 55  */
  {       /* 20 Mhz */ {   91.0f,         /* SGI */  101.1f, },
	  /* 40 Mhz */ {  189.0f,         /* SGI */  210.0f, },
  },
  /* MCS 56  */
  {       /* 20 Mhz */ {   78.0f,         /* SGI */   86.7f, },
	  /* 40 Mhz */ {  162.0f,         /* SGI */  180.0f, },
  },

  /* MCS 57  */
  {       /* 20 Mhz */ {   91.0f,         /* SGI */  101.1f, },
	  /* 40 Mhz */ {  189.0f,         /* SGI */  210.0f, },
  },

  /* MCS 58  */
  {       /* 20 Mhz */ {  104.0f,         /* SGI */  115.6f, },
	  /* 40 Mhz */ {  216.0f,         /* SGI */  240.0f, },
  },

  /* MCS 59  */
  {       /* 20 Mhz */ {  117.0f,         /* SGI */  130.0f, },
	  /* 40 Mhz */ {  243.0f,         /* SGI */  270.0f, },
  },

  /* MCS 60  */
  {       /* 20 Mhz */ {  104.0f,         /* SGI */  115.6f, },
	  /* 40 Mhz */ {  216.0f,         /* SGI */  240.0f, },
  },

  /* MCS 61  */
  {       /* 20 Mhz */ {  117.0f,         /* SGI */  130.0f, },
	  /* 40 Mhz */ {  243.0f,         /* SGI */  270.0f, },
  },

  /* MCS 62  */
  {       /* 20 Mhz */ {  130.0f,         /* SGI */  144.4f, },
	  /* 40 Mhz */ {  270.0f,         /* SGI */  300.0f, },
  },

  /* MCS 63  */
  {       /* 20 Mhz */ {  130.0f,         /* SGI */  144.4f, },
	  /* 40 Mhz */ {  270.0f,         /* SGI */  300.0f, },
  },

  /* MCS 64  */
  {       /* 20 Mhz */ {  143.0f,         /* SGI */  158.9f, },
	  /* 40 Mhz */ {  297.0f,         /* SGI */  330.0f, },
  },

  /* MCS 65  */
  {       /* 20 Mhz */ {   97.5f,         /* SGI */  108.3f, },
	  /* 40 Mhz */ {  202.5f,         /* SGI */  225.0f, },
  },

  /* MCS 66  */
  {       /* 20 Mhz */ {  117.0f,         /* SGI */  130.0f, },
	  /* 40 Mhz */ {  243.0f,         /* SGI */  270.0f, },
  },

  /* MCS 67  */
  {       /* 20 Mhz */ {  136.5f,         /* SGI */  151.7f, },
	  /* 40 Mhz */ {  283.5f,         /* SGI */  315.0f, },
  },

  /* MCS 68  */
  {       /* 20 Mhz */ {  117.0f,         /* SGI */  130.0f, },
	  /* 40 Mhz */ {  243.0f,         /* SGI */  270.0f, },
  },

  /* MCS 69  */
  {       /* 20 Mhz */ {  136.5f,         /* SGI */  151.7f, },
	  /* 40 Mhz */ {  283.5f,         /* SGI */  315.0f, },
  },

  /* MCS 70  */
  {       /* 20 Mhz */ {  156.0f,         /* SGI */  173.3f, },
	  /* 40 Mhz */ {  324.0f,         /* SGI */  360.0f, },
  },

  /* MCS 71  */
  {       /* 20 Mhz */ {  175.5f,         /* SGI */  195.0f, },
	  /* 40 Mhz */ {  364.5f,         /* SGI */  405.0f, },
  },

  /* MCS 72  */
  {       /* 20 Mhz */ {  156.0f,         /* SGI */  173.3f, },
	  /* 40 Mhz */ {  324.0f,         /* SGI */  360.0f, },
  },

  /* MCS 73  */
  {       /* 20 Mhz */ {  175.5f,         /* SGI */  195.0f, },
	  /* 40 Mhz */ {  364.5f,         /* SGI */  405.0f, },
  },

  /* MCS 74  */
  {       /* 20 Mhz */ {  195.0f,         /* SGI */  216.7f, },
	  /* 40 Mhz */ {  405.0f,         /* SGI */  450.0f, },
  },

  /* MCS 75  */
  {       /* 20 Mhz */ {  195.0f,         /* SGI */  216.7f, },
	  /* 40 Mhz */ {  405.0f,         /* SGI */  450.0f, },
  },

  /* MCS 76  */
  {       /* 20 Mhz */ {  214.5f,         /* SGI */  238.3f, },
	  /* 40 Mhz */ {  445.5f,         /* SGI */  495.0f, },
  },

};


#endif


