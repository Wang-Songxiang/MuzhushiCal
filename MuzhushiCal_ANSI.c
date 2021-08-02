#include<stdio.h>

int StarCal(int n,int t){
    int s=0;
    if(n==1 && t==2){
        s=30;
    }else if(n==1 && t==3){
        s=130;
    }else if(n==1 && t==4){
        s=250;
    }else if(n==1 && t==5){
        s=400;
    }else if(n==2 && t==3){
        s=100;
    }else if(n==2 && t==4){
        s=220;
    }else if(n==2 && t==5){
        s=370;
    }else if(n==3 && t==4){
        s=120;
    }else if(n==3 && t==5){
        s=270;
    }else if(n==4 && t==5){
        s=150;
    }
    return s;
}

int WeaponCal(int n,int t){
    int s=0;
    if(n==0){
        s=50;
        n=30;
    }
    if(t<=130){
        s=((t-n)/20)*10+s;
    }else if(n>=130&&t>130){
        s=((t-n)/10)*15;
    }else if(n<130&&t>130){
        s=(((130-n)/20)*10)+(((t-130)/10)*15)+s;
    }
    return s;
}

int StoneCAL(int sum,int b){
    int res;
    if(b<=20){
        if(sum<=20-b){
            res=sum;
        }
        else if(sum>20-b&&sum<=40-b){
            res=(20-b)+(sum-(20-b))*2;
        }
        else if(sum>40-b&&sum<=60-b){
            res=(20-b)+40+(sum-(20-b)-20)*3;
        }
        else if(sum>60-b&&sum<=80-b){
            res=(20-b)+40+60+(sum-(20-b)-40)*4;
        }
        else if(sum>80-b){
            res=(20-b)+40+60+80+(sum-(20-b)-60)*5;
        }
    }else if(b>20&&b<=40){
        if(sum<=40-b){
            res=(40-b)*2;
        }
        else if(sum>40-b&&sum<=60-b){
            res=(40-b)*2+(sum-(40-b))*3;
        }
        else if(sum>60-b&&sum<=80-b){
            res=(40-b)*2+60+(sum-(40-b)-20)*4;
        }
        else if(sum>80-b){
            res=(40-b)+60+80+(sum-(40-b)-40)*5;
        }
    }else if(b>40&&b<=60){
        if(sum<=60-b){
            res=(60-b)*3;
        }
        else if(sum>60-b&&sum<=80-b){
            res=(60-b)*3+(sum-(60-b))*4;
        }
        else if(sum>80-b){
            res=(60-b)*3+80+(sum-(60-b)-20)*5;
        }
    }else if(b>60&&b<=80){
        if(sum<=80-b){
            res=(80-b)*4;
        }
        else if(sum>80-b){
            res=(80-b)*4+(sum-(80-b))*5;
        }
    }else if(b>80){
        res=sum*5;
    }
    return res;
}

int main(){
    int nstar,tstar,option,NumOfStone;
    int nwep,twep,result=0,buy;
    int temps=0,tempw=0,sum=0;
    printf("欢迎使用母猪石计算器\n");
    loop:printf("选择需要计算的选项:1.升星  2.升专武   3.都升  4.点错了(退出)\n");
    scanf("%d",&option);
    if(option==1||option==2||option==3){
        printf("请输入已有碎片数量\n");
        scanf("%d",&NumOfStone);
        printf("请输入已经购买的碎片数量\n");
        scanf("%d",&buy);
        if(option==1||option==3){
            printf("请输入当前星级\n");
            scanf("%d",&nstar);
            printf("请输入目标星级\n");
            scanf("%d",&tstar);
            temps=StarCal(nstar,tstar);
        }if(option==2||option==3){
            printf("请输入当前专武等级上限(未开放写0)\n");
            scanf("%d",&nwep);
            printf("请输入目标专武等级上限\n");
            scanf("%d",&twep);
            tempw=WeaponCal(nwep,twep);
        }
    }else{
        return 0;
    }
    sum=temps+tempw-NumOfStone;
    result=StoneCAL(sum,buy);
    printf("共需要%d片碎片，需要的母猪石为%d个\n",sum,result);
    printf("是否继续计算:1.是  2.退出\n");
    scanf("%d",&option);
    if(option==1)goto loop;
    else return 0;
}

