#ifndef UNTITLED1_CH9329_H
#define UNTITLED1_CH9329_H
#include <Arduino.h>

enum all_cmd {
    CMD_GET_INFO = 0x01,
//获取芯片版本等信息
//通过该命令向芯片获取版本号、
//USB 枚举状态、键盘大小写指示灯
//状态等信息
    CMD_SEND_KB_GENERAL_DATA = 0x02,
//发送 USB 键盘普通数据
//通过该命令向芯片发送普通键盘
//数据包，模拟普通按键按下或释放
//动作
    CMD_SEND_KB_MEDIA_DATA = 0x03,
//发送 USB 键盘多媒体数据
//通过该命令向芯片发送多媒体键
//盘数据包，模拟多媒体按键按下或
//释放动作
    CMD_SEND_MS_ABS_DATA = 0x04,
//发送 USB 绝对鼠标数据
//通过该命令向芯片发送绝对鼠标
//数据包，模拟绝对鼠标相关动作
    CMD_SEND_MS_REL_DATA = 0x05,
//发送 USB 相对鼠标数据
//通过该命令向芯片发送相对鼠标
//数据包，模拟相对鼠标相关动作
    CMD_SEND_MY_HID_DATA = 0x06,
//发送 USB 自定义 HID 设备数据
//通过该命令向芯片发送自定义 HID
//类设备数据包
    CMD_READ_MY_HID_DATA = 0x87,
//读取 USB 自定义 HID 设备数据
//通过该命令从芯片读取自定义 HID
//类设备数据包
//注：PC 机向芯片下传 1 包自定义
//HID 数据包后，由芯片串口自动打
//包发送给外围串口设备
    CMD_GET_PARA_CFG = 0x08,
//获取参数配置
//通过该命令向芯片获取当前参数
//配置信息
    CMD_SET_PARA_CFG = 0x09,
//设置参数配置
//通过该命令向芯片设置当前参数
//配置信息
    CMD_GET_USB_STRING = 0x0A,
//获取字符串描述符配置
//通过该命令向芯片获取当前所使
//CH9329 芯片串口通信协议 5 http://wch.cn
//用的 USB 字符串描述符配置
    CMD_SET_USB_STRING = 0x0B,
//设置字符串描述符配置
//通过该命令向芯片设置当前所使
//用的 USB 字符串描述符配置
    CMD_SET_DEFAULT_CFG = 0x0C,
//恢复出厂默认配置
//通过该命令将芯片的参数配置及
//字符串配置信息恢复到出厂默认
//设置
    CMD_RESET = 0x0F
//        复位芯片
//通过该命令控制芯片进行软件复
//位控制
};


enum control_key {
    KEY_LEFT_CTRL = 0x01,
    KEY_LEFT_SHIFT = 0x02,
    KEY_LEFT_ALT = 0x04,
    KEY_LEFT_GUI = 0x08,
    KEY_LEFT_WIN = 0x08,
    KEY_RIGHT_CTRL = 0x10,
    KEY_RIGHT_SHIFT = 0x20,
    KEY_RIGHT_ALT = 0x40,
    KEY_RIGHT_GUI = 0x80,
    KEY_RIGHT_WIN = 0x80
};

enum hid_code{
    HID_BACKSPACE = 0x2A,
    HID_TAB = 0x2B,
    HID_CAPSLOCK = 0x39,
    HID_ENTER = 0x2B,
    HID_L_SHIFT = 0xE1,
    HID_R_SHIFT = 0xE5,
    HID_L_CTRL = 0xE0,
    HID_L_ALT = 0xE2,
    HID_SPACE = 0x2C,
    HID_R_ALT = 0xE6,
    HID_R_CTRL = 0xE4,
    HID_INSERT = 0x49,
    HID_DELETE = 0x4C,
    HID_HOME = 0x4A,
    HID_END = 0x4D,
    HID_LEFT_ARROW =  0x50,
    HID_DOWN_ARROW =  0x51,
    HID_UP_ARROW =  0x52,
    HID_RIGHT_ARROW =  0x4F,
    HID_PG_UP = 0x4B,
    HID_PG_DN = 0x4E,
    HID_NUM_LOCK = 0x53,
    HID_KEYPAD_1 = 0x59,
    HID_KEYPAD_END = 0x59,
    HID_KEYPAD_2 = 0x5A,
    HID_KEYPAD_DOWN = 0x5A,
    HID_KEYPAD_3 = 0x5B,
    HID_KEYPAD_PG_DN = 0x5B,
    HID_KEYPAD_4 = 0x5C,
    HID_KEYPAD_LEFT = 0x5C,
    HID_KEYPAD_5 = 0x5D,
    HID_KEYPAD_6 = 0x5E,
    HID_KEYPAD_RIGHT = 0x5E,
    HID_KEYPAD_7 = 0x5F,
    HID_KEYPAD_HOME = 0x5F,
    HID_KEYPAD_8 = 0x60,
    HID_KEYPAD_UP = 0x60,
    HID_KEYPAD_9 = 0x61,
    HID_KEYPAD_PG_UP = 0x61,
    HID_KEYPAD_0 = 0x62,
    HID_KEYPAD_INS = 0x62,
    HID_KEYPAD_DOT = 0x63,
    HID_KEYPAD_DEL = 0x63,

    HID_KEYPAD_ADD = 0x57,
    HID_KEYPAD_SUB = 0x56,
    HID_KEYPAD_MUL = 0x55,
    HID_KEYPAD_DIV = 0x54,
    HID_KEYPAD_ENTER = 0x58,

    HID_ESC =  0x29,
    HID_F1 =  0x3A,
    HID_F2 =  0x3B,
    HID_F3 =  0x3C,
    HID_F4 =  0x3D,
    HID_F5 =  0x3E,
    HID_F6 =  0x3F,
    HID_F7 =  0x40,
    HID_F8 =  0x41,
    HID_F9 =  0x42,
    HID_F10 =  0x43,
    HID_F11 =  0x44,
    HID_F12 =  0x45,
    HID_PRINT_SCREEN = 0x46,
    HID_SCROLL_LOCK = 0x47,
    HID_PAUSE = 0x48,
    HID_L_WIN = 0xE3,
    HID_R_WIN = 0xE7
};

enum mouse_button{
    MOUSE_LEFT_BUTTON = 0x01,
    MOUSE_RIGHT_BUTTON = 0x02,
    MOUSE_MIDDLE_BUTTON = 0x04
};

const uint16_t REPORT_ID_ACPI   = 0x0100;
const uint16_t ACPI_WAKE_UP     = REPORT_ID_ACPI | ( 1 << 2 );
const uint16_t ACPI_SLEEP       = REPORT_ID_ACPI | ( 1 << 1 );
const uint16_t ACPI_POWER       = REPORT_ID_ACPI | ( 1 << 0 );

const uint32_t REPORT_ID_MEDIA  = 0x02000000;

const uint32_t MEDIA_EJECT              = (REPORT_ID_MEDIA | ( 1 << 23 ));
const uint32_t MEDIA_CD_STOP            = (REPORT_ID_MEDIA | ( 1 << 22 ));
const uint32_t MEDIA_PREV_TRACK         = (REPORT_ID_MEDIA | ( 1 << 21 ));
const uint32_t MEDIA_NEXT_TRACK         = (REPORT_ID_MEDIA | ( 1 << 20 ));
const uint32_t MEDIA_PLAY_OR_PAUSE      = (REPORT_ID_MEDIA | ( 1 << 19 ));
const uint32_t MEDIA_MUTE               = (REPORT_ID_MEDIA | ( 1 << 18 )) ;
const uint32_t MEDIA_VOLUME_REDUCE      = (REPORT_ID_MEDIA | ( 1 << 17 )) ;
const uint32_t MEDIA_VOLUME_INCREASE    = (REPORT_ID_MEDIA | ( 1 << 16 )) ;
const uint32_t MEDIA_REFRESH            = (REPORT_ID_MEDIA | ( 1 << 15 )) ;
const uint32_t MEDIA_WWW_STOP           = (REPORT_ID_MEDIA | ( 1 << 14 )) ;
const uint32_t MEDIA_WWW_FORWARD        = (REPORT_ID_MEDIA | ( 1 << 13 )) ;
const uint32_t MEDIA_WWW_BACK           = (REPORT_ID_MEDIA | ( 1 << 12 )) ;
const uint32_t MEDIA_WWW_HOME           = (REPORT_ID_MEDIA | ( 1 << 11 )) ;
const uint32_t MEDIA_WWW_FAVORITES      = (REPORT_ID_MEDIA | ( 1 << 10 )) ;
const uint32_t MEDIA_WWW_SEARCH         = (REPORT_ID_MEDIA | ( 1 << 9 )) ;
const uint32_t MEDIA_EMail              = (REPORT_ID_MEDIA | ( 1 << 8 )) ;
const uint32_t MEDIA_REWIND             = (REPORT_ID_MEDIA | ( 1 << 7 )) ;
const uint32_t MEDIA_RECORD             = (REPORT_ID_MEDIA | ( 1 << 6 )) ;
const uint32_t MEDIA_MINIMIZE           = (REPORT_ID_MEDIA | ( 1 << 5 )) ;
const uint32_t MEDIA_MY_COMPUTER        = (REPORT_ID_MEDIA | ( 1 << 4 )) ;
const uint32_t MEDIA_SCREEN_SAVE        = (REPORT_ID_MEDIA | ( 1 << 3 )) ;
const uint32_t MEDIA_CALCULATOR         = (REPORT_ID_MEDIA | ( 1 << 2 )) ;
const uint32_t MEDIA_EXPLORER           = (REPORT_ID_MEDIA | ( 1 << 1 )) ;
const uint32_t MEDIA_MEDIA              = (REPORT_ID_MEDIA | ( 1 << 0 )) ;

const uint32_t MEDIA_PLAY = MEDIA_PLAY_OR_PAUSE ;
const uint32_t MEDIA_PAUSE = MEDIA_PLAY_OR_PAUSE ;

enum chip_ver {
    V1_0 = 0x30,
    V1_1 = 0x31
};



typedef struct uart_fmt{
	char HEAD[2]; // 帧头：占 2 个字节，固定为 0x57、0xAB
	char ADDR; // 地址码：占 1 个字节，默认为 0x00，可接收任意地址码的命令包，如果芯片地址设置成 0x01---0xFE，则只能接收对应地址码或地址码为 0xFF 的命令包。0xFF 为广播包，芯片不需 要进行应答；
	char CMD; // 命令码：占 1 个字节，外围串口设备发起的帧的命令码有效范围为：0x01---0x3F，CH9329 芯片发送正常应答包时的命令码为：原命令码 | 0x80；CH9329 芯片发送异常应答包时的命 令码为：原命令码 | 0xC0；
	char LEN; // 后续数据长度：占 1 个字节，主要用于记录该包实际后续数据的长度，仅包含后续数据部分，不包括帧头字节、地址码、命令码和累加和字节；
	char DATA[64]; // 后续数据：占 N 个字节，N 有效范围为 0---64。typedef
	char SUM; // 累加和：占 1 个字节，计算方式为： SUM = HEAD+ADDR+CMD+LEN+DATA
}UART_FMT;

class CH9329 {
private:
    HardwareSerial * _serial;
    uint8_t _addr;
    uart_fmt _lastUartData{};
    void writeUart( uart_fmt * data );
    uart_fmt * readUart( uart_fmt *  ) ;
    void cmdSendKbGeneralData(uint8_t * key );
    void cmdSendKbMediaData();
    void cmdSendMsAbsData();
    void cmdSendMsRelData(uint8_t * data );
    void cmdSendMyHidData();
    uart_fmt * cmdReadMyHidData(uart_fmt * );
    uart_fmt * cmdGetRaraCFG(uart_fmt * );
    uart_fmt cmdSetRaraCFG();
    uart_fmt cmdGetUsbString();
    uart_fmt cmdSetUsbString();
    uart_fmt cmdSetDefaultCfg();
    void cmdReset();

public:
    CH9329(  HardwareSerial *serial , uint32_t _baud  = 9600, uint8_t addr = 0x00);
    uart_fmt * cmdGetInfo(uart_fmt * );
    uint8_t sum(uart_fmt * );
    void press( uint8_t hid_code , uint8_t control = 0 );
    void pressASCII( char key , uint8_t control = 0 );
    void releaseAll();
    void sendString(char * string , uint8_t len );

    uint8_t getChipVer();
    bool isUSBConnected();
    bool isCapsLock();
    bool isNumLock();
    bool isScrollLock();

    void mouseRelease();
    void mouseMove( uint8_t horizontal , uint8_t vertical , uint8_t ms_key = 0);
    void mouseWheel( uint8_t scale , uint8_t ms_key = 0);
    void mousePress( uint8_t ms_key = MOUSE_LEFT_BUTTON );
    void mouseClick( uint8_t ms_key = MOUSE_LEFT_BUTTON , uint8_t delay_ms = 10 );

    void customizeCmd( uint8_t cmd , uint8_t * data , uint8_t len);
    uart_fmt * getLastUartData();
};


#endif //UNTITLED1_CH9329_H
