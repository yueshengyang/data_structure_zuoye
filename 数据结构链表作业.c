#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct line
{
    char name[20];
    char brand[20];
    float price;
    int num;
    struct line *next;
};
typedef struct line LINE;
LINE * struct_line();
void output();
void increase_new_shopping(LINE *lin);
void decrease_old_shopping(LINE *lin);
void update_shopping(LINE *lin);
void lookfor_the_infomation(LINE *lin);
void shengxupailie(LINE *lin);

int cnt=1;//记录节点

void output_bin(LINE* lin)
{
    LINE *pr=lin;
    FILE* fp;
    if((fp=fopen("E:\\shangpin.bin","wb"))==NULL)
    {
        printf("Failure to open shangpin.bin!\n");
        return;
    }
    fputc(cnt,fp);
    while(pr!=NULL)
    {
        fwrite(pr,sizeof(LINE),1,fp);
        pr=pr->next;
    }
}

void input_bin(LINE*lin)
{
    LINE *pr=lin;
    FILE* fp;
    if((fp=fopen("E:\\shangpin.bin","rb"))==NULL)
    {
        printf("Failure to open shangpin.bin!\n");
        return;
    }
    cnt=fgetc(fp);
    int i;
    for(i=0;i<cnt;i++)
    {
        fread(pr,sizeof(LINE),1,fp);
        LINE *l=malloc(sizeof(LINE));
        pr->next=l;
        pr=l;
    }
}


int main()
{
    int a;
    LINE *lin=malloc(sizeof(LINE));
    do
    {
        output();
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            lin=struct_line();
            break;
        case 2:
            increase_new_shopping(lin);
            break;
        case 3:
            decrease_old_shopping(lin);
            break;
        case 4:
            update_shopping(lin);
            break;
        case 5:
            lookfor_the_infomation(lin);
            break;
        case 6:
            shengxupailie(lin);
            break;
        case 7:
            output_bin(lin);
            break;
        case 8:
            input_bin(lin);
            break;
        }

    }while(a>=0);
    return 0;
}
void output()
{
    printf("请选择你要进行的操作：\n");
    printf("1、初始化建立新的数据表格\n");
    printf("2、增加现有的商品种类\n");
    printf("3、删除现有的商品种类\n");
    printf("4、进货或提货更新商品信息\n");
    printf("5、按照商品名称查询相关商品信息\n");
    printf("6、按照商品价格的升序排列链表\n");
    printf("7、结束营业，将现有信息存入文件\n");
    printf("8、开始营业，从文件中读入数据\n");
    printf("-1、结束程序的运行\n");
}
LINE * struct_line()//对表头初始化
{
    LINE *lines=malloc(sizeof(LINE));
    lines->brand;
    lines->name;
    lines->num=0;
    lines->price=0;
    lines->next=NULL;
    return lines;
}
void increase_new_shopping(LINE *lin)//增加新商品种类并链入链表
{
    LINE *l=malloc(sizeof(LINE));
    printf("请输入新商品名称：\n");
    scanf("%s",&l->name);
    printf("请输入新商品品牌：\n");
    scanf("%s",&l->brand);
    printf("请输入新商品数量：\n");
    scanf("%d",&l->num);
    printf("请输入新商品价格：\n");
    scanf("%f",&l->price);
    l->next=lin->next;
    lin->next=l;
    cnt++;
}
void decrease_old_shopping(LINE *lin)
{
    char a[12];
    LINE *l=lin;
    printf("请输入需要删除的货物名称：\n");
    scanf("%s",a);
    while (l->next!=NULL)
    {
        if (strcmp(a,l->next->name)==0)
        {
            l->next=l->next->next;
            free(l->next);
            break;
        }
        l=l->next;
        if (l->next==NULL)
        {
            printf("商品列表为空或列表中无此商品\n");
            break;
        }
    }
}
void update_shopping(LINE *lin)
{
    LINE *l=lin;
    int b;
    char *a=NULL;
    printf("请输入要更新的商品的名称：\n");
    gets(a);
    while(l->next!=NULL)
    {
        if (a==l->next->name)
        {
            b=l->num;
            printf("请输入商品现有数量：\n");
            scanf("%d",&l->num);
            if(l->num<0)
            {
                printf("输入的数量有误！\n");
                l->num=b;
            }
            break;
        }
        l=l->next;
        if (l->next==NULL)
        {
            printf("列表中无此商品！\n");
            break;
        }
    }
}
void lookfor_the_infomation(LINE *lin)
{
    char *a=malloc(20*sizeof(char));
    LINE *l=lin;
    printf("请输入要查询的商品名称：\n");
    scanf("%s",a);
    while (l->next!=NULL)
    {
        if(strcmp(a,l->next->name)==0)
        {
            printf("商品的名称为：%s\n",l->next->name);
            printf("商品的品牌为：%s\n",l->next->name);
            printf("商品的价格为：%f\n",l->next->price);
            printf("剩余商品的数量为：%d\n",l->next->num);
            break;
        }
        l=l->next;
        if(l->next==NULL)
        {
            printf("仓库中无此商品或商品名称输入错误！\n");
            break;
        }
    }
    free(l);
}
void shengxupailie(LINE *lin)
{
    LINE *start=malloc(sizeof(LINE));
    LINE *tail=malloc(sizeof(LINE));
    LINE *a=malloc(sizeof(LINE));
    tail=lin;
    start->next=lin;
    while(tail->next!=NULL)
    {
        LINE *min=tail->next,*p=tail->next->next;
        while(p!=NULL)
        {
            if(p->price<min->price)
                min=p;
            p=p->next;
        }
        strcpy(a->brand,min->brand);
        strcpy(a->name,min->name);
        a->num=min->num;
        a->price=min->price;
        strcpy(min->brand,tail->next->brand);//min->brand=tail->next->brand;
        strcpy(min->name,tail->next->name);//min->name=tail->next->name;
        min->num=tail->next->num;
        min->price=tail->next->price;
        strcpy(tail->next->brand,a->brand);//tail->next->brand=a->brand;
        strcpy(tail->next->name,a->name);//tail->next->name=a->name;
        tail->next->num=a->num;
        tail->next->price=a->price;
        tail=tail->next;
    }
    lin=start->next;
    free(start);
}





