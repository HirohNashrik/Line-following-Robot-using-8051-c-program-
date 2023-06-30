#include <reg51.h>
#define lcd P1

sbit mot1=P0^2;
sbit mot2=P0^3;
sbit mot3=P0^4;
sbit mot4=P0^5;

sbit ir_left=P2^0;
sbit ir_right=P2^1;

sbit rs=P2^2;
sbit rw=P2^3;
sbit e=P2^4;

void forward (void);
void backward (void);
void left (void);
void right (void);
void cmd(unsigned int c);
void ldata(unsigned int c);
void delay(unsigned int t);

void delay(unsigned int t)
{
    int i,j;
    for(i=0;i<t;i++)
    for(j=0;j<500;j++);
}

void string(char *s)
{
    while(*s) {
         ldata(*s++);
    }
}

void cmd(unsigned int c)
{
    lcd=c;
    rs=0;
    rw=0;
    e=1;
    delay(5);
    e=0;
}

void ldata(unsigned int c)
{
    lcd=c;
    rs=1;
    rw=0;
    e=1;
    delay(5);
    e=0;
}

void forward(void)
{
    mot1=1;
    mot2=0;
    mot3=1;
    mot4=0;
}

void backward(void)
{
    mot1=0;
    mot2=1;
    mot3=0;
    mot4=1;
}

void left(void)
{
    mot1=1;
    mot2=0;
    mot3=0;
    mot4=0;
}

void right(void)
{
    mot1=0;
    mot2=0;
    mot3=1;
    mot4=0;
}

void stop(void)
{
    mot1=0;
    mot2=0;
    mot3=0;
    mot4=0;
}

void main()
{
    cmd(0x38);
    cmd(0x10);
    cmd(0x0c);

    ir_left=1;
    ir_right=1;

    if(ir-left==0 && ir_right==0)
    {
        cmd(0x80);
        string("moving forward");
        forward();
    }
    else if(ir_left==1 && ir__right==1)
    {
        cmd(0x80);
        string("stopping")
        stop();
    }
    else if(ir_left==0 && ir__right==1)
    {
        cmd(0x80);
        string("moving left")
        left();
    }
    else if(ir_left==1 && ir__right==0)
    {
        cmd(0x80);
        string("moving right")
        right();
    }
}

