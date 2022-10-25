#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("计算器");

    QFont f("仿宋",14);
    ui->mainLineEdit->setFont(f);
    ui->mainLineEdit2->setFont(f);

    QIcon con("C:\\Users\\xuxuxuxuxu\\Desktop\\del.png");
    ui->ButtonDel->setIcon(con);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Button1_clicked()
{
    expression += "1";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button2_clicked()
{
    expression += "2";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button3_clicked()
{
    expression += "3";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button4_clicked()
{
    expression += "4";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button5_clicked()
{
    expression += "5";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button6_clicked()
{
    expression += "6";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button7_clicked()
{
    expression += "7";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button8_clicked()
{
    expression += "8";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button9_clicked()
{
    expression += "9";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonClear_clicked()
{
    expression ="";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonAdd_clicked()
{
    expression += "+";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonSub_clicked()
{
    expression += "-";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonMul_clicked()
{
    expression += "*";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonDiv_clicked()
{
    expression += "/";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_Button0_clicked()
{
    expression += "0";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonL_clicked()
{
    expression += "(";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonR_clicked()
{
    expression += ")";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonDel_clicked()
{
    int len=expression.size();
    QString A;
    for(int i=1;i<len;i++)A+=expression[i-1];
    expression=A;
    ui->mainLineEdit->setText(expression);
}

int change(QChar c)
{
    if(c=='0')return 0;
    if(c=='1')return 1;
    if(c=='2')return 2;
    if(c=='3')return 3;
    if(c=='4')return 4;
    if(c=='5')return 5;
    if(c=='6')return 6;
    if(c=='7')return 7;
    if(c=='8')return 8;
    if(c=='9')return 9;
    return 0;
}

#define int long long

QChar change2(int c)
{
    if(c==0)return '0';
    if(c==1)return '1';
    if(c==2)return '2';
    if(c==3)return '3';
    if(c==4)return '4';
    if(c==5)return '5';
    if(c==6)return '6';
    if(c==7)return '7';
    if(c==8)return '8';
    if(c==9)return '9';
    return '0';
}
int Val2(QString s)
{
    int n=s.size();
    int res=0;
    for(int i=0;i<n;i++)
        res=res*10+change(s[i]);
    return res;
}

double Val(QString s)
{
    int n=s.size();
    int pos=0;
    for(int i=0;i<n;i++)
        if(s[i]=='.')pos=i;
    if(pos==0)
    {
        double res=1.0;
        res=res*Val2(s);
        return res;
    }
    else{
        double res1=1.0,res2=1.0;
        QString A,B;
        for(int i=0;i<pos;i++)
            A+=s[i];
        for(int i=pos+1;i<n;i++)
        {
            B+=s[i];
            res2=res2*0.1;
        }
        res1=res1*Val2(A);
        res2=res2*Val2(B);
        return res1+res2;
    }
}

QString motify(double x)
{
    QString res;
    int n=0;
    int sum=(int)(x*100000);
    QChar xjh[105];
    if(sum==0){res="0";return res;}
    if(sum<0){res="-";sum=-sum;}
    while(sum>0)
    {
        xjh[++n]=change2(sum%10);
        sum/=10;
    }
    QString A="";
    for(int i=n;i;i--)A+=xjh[i];
    for(int i=1;i<=n-5;i++)res+=A[i-1];
    if(n-5<1)res+="0";
    res+=".";
    for(int i=n-4;i<=n;i++)res+=A[i-1];
    return res;
}

double kuai(double a,double b)
{
    double res=1.0;
    int bb=(int)b;
    while(bb>0)
    {
        if(bb&1)res=res*a;
        a=a*a;
        bb=bb/2;
    }
    return res;
}

void Widget::on_ButtonEquel_clicked()
{
    QChar zhan[105];
    int len=expression.size();
    int tot=0,n=0;
    QString xu;
    QString a[105];

    for(int i=1;i<=len;i++)
    {
        QChar c=expression[i-1];
        if((c>='0'&&c<='9')||c=='.')xu+=c;
        else{
            if(xu!="")a[++n]=xu;
            xu="";
        }
        if(c=='(')zhan[++tot]=c;
        if(c=='+'||c=='-')
        {
            while(tot>0&&zhan[tot]!='(')
            {
                a[++n]=zhan[tot];
                tot--;
            }
            zhan[++tot]=c;
        }
        if(c=='*'||c=='/')
        {
            while(tot>0&&(zhan[tot]=='*'||zhan[tot]=='/'))
            {
                a[++n]=zhan[tot];
                tot--;
            }
            zhan[++tot]=c;
        }
        if(c=='^')
        {
            while(tot>0&&zhan[tot]=='^')
            {
                a[++n]=zhan[tot];
                tot--;
            }
            zhan[++tot]=c;
        }
        if(c==')')
        {
            while(zhan[tot]!='(')
            {
                a[++n]=zhan[tot];
                tot--;
            }
            tot--;
        }
    }
    if(xu!="")a[++n]=xu;
    while(tot>0)
    {
        a[++n]=zhan[tot];
        tot--;
    }
    tot=0;
    double Ans[105];
    for(int i=1;i<=n;i++)
    {
        if(a[i]=="+")
        {
            Ans[tot-1]+=Ans[tot];
            tot--;
        }
        else if(a[i]=="-")
        {
            Ans[tot-1]-=Ans[tot];
            tot--;
        }
        else if(a[i]=="*")
        {
            Ans[tot-1]*=Ans[tot];
            tot--;
        }
        else if(a[i]=="/")
        {
            Ans[tot-1]/=Ans[tot];
            tot--;
        }
        else if(a[i]=="^")
        {
            Ans[tot-1]=kuai(Ans[tot-1],Ans[tot]);
            tot--;
        }
        else{
            Ans[++tot]=Val(a[i]);
        }
    }
    expression=motify(Ans[1]);
    ui->mainLineEdit->setText(expression);
}

void Widget::on_pushButton1_clicked()
{
    QChar zhan[105];
    int len=expression.size();
    int tot=0,n=0;
    QString xu;
    QString a[105];
    for(int i=1;i<=len;i++)
    {
        QChar c=expression[i-1];
        if((c>='0'&&c<='9')||c=='.')xu+=c;
        else{
            if(xu!="")a[++n]=xu;
            xu="";
        }
        if(c=='(')zhan[++tot]=c;
        if(c=='+'||c=='-')
        {
            while(tot>0&&zhan[tot]!='(')
            {
                a[++n]=zhan[tot];
                tot--;
            }
            zhan[++tot]=c;
        }
        if(c=='*'||c=='/')
        {
            while(tot>0&&(zhan[tot]=='*'||zhan[tot]=='/'))
            {
                a[++n]=zhan[tot];
                tot--;
            }
            zhan[++tot]=c;
        }
        if(c=='^')
        {
            while(tot>0&&zhan[tot]=='^')
            {
                a[++n]=zhan[tot];
                tot--;
            }
            zhan[++tot]=c;
        }
        if(c==')')
        {
            while(zhan[tot]!='(')
            {
                a[++n]=zhan[tot];
                tot--;
            }
            tot--;
        }
    }
    if(xu!="")a[++n]=xu;
    while(tot>0)
    {
        a[++n]=zhan[tot];
        tot--;
    }
    expression2="";
    for(int i=1;i<=n;i++)
    {
        expression2+=a[i]+" ";
    }
    ui->mainLineEdit2->setText(expression2);
}


void Widget::on_ButtonPoint_clicked()
{
    expression+=".";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonSin_clicked()
{
    Widget::on_ButtonEquel_clicked();
    double x=Val(expression);
    x=sin(x);
//    qDebug() << x;
    expression=motify(x);
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonCos_clicked()
{
    Widget::on_ButtonEquel_clicked();
    double x=Val(expression);
    x=cos(x);
    expression=motify(x);
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonDao_clicked()
{
    Widget::on_ButtonEquel_clicked();
    double x=Val(expression);
    x=1.0/x;
    expression=motify(x);
    ui->mainLineEdit->setText(expression);
}


void Widget::on_ButtonPower_clicked()
{
    expression += "^";
    ui->mainLineEdit->setText(expression);
}

