#include <stdio.h>//宋体5号
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAxVex 100//定义限制的个数
#define INFINITY 65535
typedef struct {//定义结构体的大体内容
    int num;//定义每个地址的序号
    char name[MAxVex];//景点名称
    char info[MAxVex];//景点简介
} Ding;//结构体重新命名
typedef struct {//利用图来实现功能
    Ding vexs[MAxVex];//定义结构体数组
    int arc[MAxVex][MAxVex];//用二维数组来表示每个结构体在图中的位置
    int numVertexes, numEdges;
} MGraph;
struct e{
    char a[10];
    char b[10];
}z;//定义管理员用户名以及密码
int stack[100]; //操作2所需要的全局变量
int top = -1;//初始化栈
int num;
int visited[100] = {0};
int edge2[100][100]; //操作3所需要的全局变量
int p1[100][100], d1[100][100];
void floyd(MGraph *g);//
void showBestPath(MGraph g);//最佳路径
void CreateMGraph(MGraph *G);//文件初始化
int finVex(char vex[], MGraph G);//对景点的位置坐标
void showShortestPath(MGraph G);//显示最短路径
void Dijkstra(MGraph G, int start, int end);//迪杰斯特拉
void showAll(MGraph G);//显示所有路径
void menu();
void menuOperation(MGraph G);//主菜单的选择
int showAllPath(MGraph g);
void dfs(MGraph g, int a, int b);
void menu2();
void guan(MGraph G);
void chaxun(MGraph G);
//void mima();
int main() {
    MGraph G;//初始化结构体
    CreateMGraph(&G);//读取文件信息，利用文件内容初始化————————————————————需要在这里加上管理员权限修改，添加，删除信息
    menuOperation(G);
    return 0;
}
void menu() {
    printf("\t\t ————————————————————西邮导游系统—————————————————— \n");
    printf("\t\t*\t\t 1. 查询所有景点的详细信息                     \n");
    printf("\t\t*\t\t 2. 查询两个景点之间的所有路径                 \n");
    printf("\t\t*\t\t 3. 查询两个景点之间的最佳路径                 \n");
    printf("\t\t*\t\t 4. 查询两个景点之间的最短路径                 \n");
    printf("\t\t*\t\t 5. 退出程序                                  \n");
    printf("\t\t*\t\t 6. 管理员登录                                \n");
    printf("\t\t*\t\t 7. 查询信息                                  \n");
    printf("\t\t——————————————————————————————————————————————————\n");
}
void guan(MGraph G){
    int i=0,j=0,t=0,k=0;
    char s[100],d[100],a[100],a1[100];
    FILE *p;
    if((p=fopen("d:\\guanli.txt","r+"))==NULL){
        p=fopen("d:\\guanli.txt","w+");
        t=1;
    }
    if(t==1){
        //system("cls");
        printf("\n\n\n");
        printf("当前无管理员！！！\n");
        printf("请输入需要注册的管理员信息：\n");
        printf("请输入正在注册的管理员用户名:\n");
        scanf("%s",s);
        printf("");
        printf("请设置管理员密码：\n");
        printf("");
        /*d[i]=getch();
        printf("%c",d[i]);
        while(d[i]!='n'){
            i=i+1;
            d[i]=getch();
            printf("%c",d[i]);
        }
        d[i]='\0';
        i=0;
        printf("\n请重新输入密码：\n");
        a[i]=getch();
        printf("%c",a[i]);
        while(a[i]!='n'){
            i=i+1;
            a[i]=getch();
            printf("%c",a[i]);
        }
        a[i]='\0';
        printf("测试结果:\n");
        printf(a);
        printf("\n");
        printf(d);
        printf("\n");*/
        scanf("%s",d);
        printf("请重新确认管理员密码：\n");
        scanf("%s",a);
        if(!strcmp(a,d)){
            strcpy(z.a,s);
            strcpy(z.b,d);
            fprintf(p,"%s %s",z.a,z.b);
            fclose(p);
            printf("\n管理员注册成功!!!\n");
            printf("请重新登录!!!\n");
            menu();
        }else{
            printf("\n两次密码不一致请重新注册!!!\n");
            printf("请重新输入！！！\n");
            guan(G);
        }
    }
    if(t==0){
        printf("请输入用户名:\n");
        scanf("%s",s);
        fscanf(p,"%s %s",z.a,z.b);
        fclose(p);
        if(!strcmp(z.a,s)){
            printf("\n请输入密码：(按n键结束)\n");
            //printf("");
            d[j]=getch();
            printf("*");
            while(d[j]!='n')//加密程序
            {
                j=j+1;
                d[j]=getch();
                printf("*");
            }
            d[j]='\0';
            //getchar();
            if(!strcmp(z.b,d)){
                printf("密码输入正确!\n");
                printf("即将进入管理员界面!\n");
                getchar();
                //system("cls");
                menu2();
                printf("请输入您将选择的序号:\n");
                scanf("%d",&num);
                if(num>0&&num<7){
                    /*printf("抱歉，目前管理功能暂未开放！！！\n");
                    getchar();
                    menu();
                    return;*/
                    if(num==1){
                        FILE *fp;
                        FILE *first;
                        FILE *file;
                        FILE *end;
                        fp=fopen("d:\\school.txt","a+");
                        first=fopen("d:\\first.txt","w+");
                        file=fopen("d:\\schools.txt","a+");
                        end=fopen("d:\\end.txt","w+");
                        int number;
                        char Name[MAxVex];
                        char introduction[MAxVex];
                        char loads[MAxVex];
                        char loadss[MAxVex];
                        int loadsss;
                        printf("请输入将要添加的景点信息:\n");
                        printf("请输入景点序号:\n");
                        scanf("%d",&number);
                        printf("请输入景点名称:\n");
                        scanf("%s",Name);
                        printf("请输入景点简介:\n");
                        scanf("%s",introduction);
                        printf("请添加新路径:\n");
                        printf("请输入起点:\n");
                        scanf("%s",loads);
                        printf("请输入终点:\n");
                        scanf("%s",loadss);
                        printf("请输入距离长度:\n");
                        scanf("%d",loadsss);
                        G.numVertexes=G.numVertexes+1;
                        G.numEdges=G.numEdges+1;
                        fprintf(fp,"\n");
                        fprintf(fp,"%d %s %s",number,Name,introduction);
                        fprintf(first,"%d",G.numVertexes);
                        fprintf(file,"\n");
                        fprintf(file,"%s %s %d",loads,loadss,loadsss);
                        fprintf(end,"%d",G.numEdges);
                        CreateMGraph(&G);///有问题
                        fclose(fp);
                        fclose(first);
                        fclose(file);
                        fclose(end);
                        //重新初始化
                    }else if(num==2){
                        printf("请选择将要修改的景点信息:\n");
                    }else if(num==3){
                        printf("请输入将要删除的景点信息:\n");
                    }else if(num==4){
                        printf("请输入将要修改路径长度的两景点信息:\n");
                    }else if(num==5){
                        FILE *p;
                        char admin[100];
                        char secrets[100];
                        printf("请修改管理员信息:\n");
                        printf("请输入管理员用户名：\n");
                        scanf("%s",admin);
                        printf("请输入管理员密码：\n");
                        scanf("%s",secrets);
                        p=fopen("d:\\guanli.txt","w+");
                        fprintf(p,"%s %s",admin,secrets);
                        fclose(p);
                        printf("密码修改成功！！！\n");
                        printf("即将返回程序主界面！！！\n");
                    }else if(num==6){
                        menu();
                        return ;
                    }else{
                        printf("输入有误！！！\n");
                        printf("正在返回主页面......");
                        getchar();
                        menu();
                        return;
                    }
                }else{
                    printf("输入有误！！！");
                    printf("即将返回主页面!!!\n");
                    menu();
                    return;
                }
            }else{
                // system("cls");
                printf("\n\n\n\n\n\n");
                printf("密码输入错误!\n");
                printf("即将返回主页面\n");
                getchar();
                menu();
            }
        }
        else{
            //system("cls");
            //printf("\n\n\n\n\n\n\n\n\n\n\n");
            printf("\n\n\n");
            printf("用户名错误!\n");
            getchar();
            getchar();
            menu();
        }
    }
}
void menu2(){
    printf("\t\t————————————————————管理员界面——————————————————————\n");
    printf("\t\t*\t\t 1.添加景点信息\n");
    printf("\t\t*\t\t 2.修改景点信息\n");
    printf("\t\t*\t\t 3.删除景点信息\n");
    printf("\t\t*\t\t 4.修改景点路径长度\n");
    printf("\t\t*\t\t 5.修改管理员信息\n");
    printf("\t\t*\t\t 6.退出\n");
    printf("\t\t___________________________________________________\n");
}
void menuOperation(MGraph G){
    int x;
    menu();
    printf("请输入您需选择的序号：\n");
    scanf("%d",&x);
    while(x!=5){
        if(x>7||x<1){
            //system("cls");
            printf("输入有误，请重新输入!!!\n");
            printf("请输入您需要选择的序号：\n");
            //menu();
            scanf("%d",&x);
        }else{
            if(x==1){
                system("地图.png");
                showAll(G);
                fflush(stdin);
                //getchar();
                printf("请输入您需选择的序号：\n");
            }else if (x==2){
                showAllPath(G);
                fflush(stdin);
                //getchar();
                printf("请输入您需选择的序号：\n");
            }else if(x==3){
                floyd(&G);
                showBestPath(G);
                fflush(stdin);
                //getchar();
                printf("请输入您需选择的序号：\n");
            }else if(x==4){
                showShortestPath(G);
                fflush(stdin);
                //getchar();
                printf("请输入您需选择的序号：\n");
            }else if(x==6){
                //该功能未完成
                // printf("此项功能暂未开启\n");
                // printf("敬请期待");
                ///menu2();
                guan(G);
                CreateMGraph(&G);
                //getchar();
                //menu();
                printf("请输入您需选择的序号：\n");
            }else if(x==7){
                chaxun(G);
                //printf("请输入您需选择的序号：\n");
            }
            //system("cls");
            //menu();
            // printf("请输入您需选择的序号：\n");
            scanf("%d",&x);
            getchar();
        }
    }
    if(x==5){
        printf("运行结束\n");
        exit(0);
    }
}
void showAll(MGraph G) {
    int i;
    for (i = 0 ; i < G.numVertexes ; i++) {//遍历G.numVertexes个信息
        printf("%03d\t%10s\t%s\n", G.vexs[i].num, G.vexs[i].name, G.vexs[i].info);///打印每组信息的详细信息
    }
    printf("\n");
}
void CreateMGraph(MGraph *G) {//读取文件进行初始化
    int i, j, w, x, y;
    char vex1[100], vex2[100];
    FILE *fp;//定义文件指针
    FILE *file;
    FILE *first;
    FILE *end;
    if ((fp = fopen("d:\\school.txt","r")) == NULL) {//以只读的方式读取文件
        printf("文件打开出错!!!\n");
        printf("异常退出！！！\n");
        exit(1);//表示异常退出，其中1意思是：系统返回的报错信息个数是1
    }
    if((file = fopen("d:\\schools.txt","r"))==NULL){
        printf("打开文件出错!!!\n");
        printf("异常退出！！！\n");
        exit(1);//表示异常退出，其中1意思是：系统返回的报错信息个数是1
    }
    if ((first = fopen("d:\\first.txt","r")) == NULL) {//以只读的方式读取文件
        printf("文件打开出错!!!\n");
        printf("异常退出！！！\n");
        exit(1);//表示异常退出，其中1意思是：系统返回的报错信息个数是1
    }
    if ((end = fopen("d:\\end.txt","r")) == NULL) {//以只读的方式读取文件
        printf("文件打开出错!!!\n");
        printf("异常退出！！！\n");
        exit(1);//表示异常退出，其中1意思是：系统返回的报错信息个数是1
    }
    fscanf(first, "%d", &G->numVertexes);
    fscanf(end,"%d", &G->numEdges);
    for (i = 0; i < G->numVertexes; i++) {//文件信息个数（景点信息个数），也可以说是读取行数
        fscanf(fp, "%d %s %s", &G->vexs[i].num, G->vexs[i].name, G->vexs[i].info);//将文件中的内容写入系统
    }//循环读取
    ///为图做准备
    for (i = 0; i < G->numVertexes; i++) {//这里是利用二维数组将每个位置都标上数值
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;//每个点都标上最大数值
        G->arc[i][i] = 0;//将正方形的从左向右对角线标上数值0
    }
    for (i = 0; i < G->numEdges; i++) {
        fgetc(file); // 过滤 "\n"
        fgetc(file); // 过滤 "<"
        fscanf(file, "%s %s %d", vex1, vex2, &w);//将两位置信息以及两位置的距离参数读入
        ///返回位置坐标
        x = finVex(vex1, *G);
        y = finVex(vex2, *G);
        ///将矩阵中的参数换成两点间的距离数值
        G->arc[x][y] = w;
        G->arc[y][x] = w;
        fgetc(file); // 过滤 ">"
    }
    fclose(fp);
    fclose(file);
    fclose(first);
    fclose(end);
}
int finVex(char vex[], MGraph G) {//用来匹配输入地点信息所对应的位置坐标
    int i;
    for (i = 0; i < G.numVertexes; i++) {
        if (strcmp(vex, G.vexs[i].name) == 0)
            return i;
    }
    return -1;
}
void showShortestPath(MGraph G) {
    int start;
    int end;
    int path[MAxVex][MAxVex] = {0};
    char str1[MAxVex], str2[MAxVex];
    printf("请输入起点\n");
    scanf("%s", str1);
    start = finVex(str1, G);
    if (start == -1)
        return;
    printf("请输入终点\n");
    scanf("%s", str2);
    end = finVex(str2, G);
    if (end == -1)
        return;
    Dijkstra(G, start, end);
}
void Dijkstra(MGraph G, int start, int end) {//迪杰斯特拉算法
    int v, w,i1, k = 0, min;
    int temp = end;
    int minPath[MAxVex];
    int count=1;
    int path[MAxVex], D[MAxVex]; //P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径长度和
    int final[MAxVex]; //final[w] = 1表示求的顶点v0到vw的最短路径
    for (v = 0; v < G.numVertexes; v++) {//开始初始化
        final[v] = 0;
        D[v] = G.arc[start][v];//有用
        path[v] = 0;
    }
    D[start] = 0;
    final[start] = 1;
    for (v = 1; v < G.numVertexes; v++) {
        min = INFINITY;
        for (w = 0; w < G.numVertexes; w++) {
            if (!final[w] && D[w] < min) {
                k = w;
                min = D[w];
            }
        }
        final[k] = 1;
        for (w = 0; w < G.numVertexes; w++) {
            if (!final[w] && (min + G.arc[k][w] < D[w])) {
                D[w] = min + G.arc[k][w];
                path[w] = k;
            }
        }
    }
    minPath[0] = end;
    while (1) {
        if (path[temp] == 0)
            break;
        minPath[count++] = path[temp];
        temp = path[temp];
    }
    minPath[count++] = start;
    printf("%s", G.vexs[start].name);
    for ( i1 = count - 2; i1 >= 0; i1--)
    {
        printf("-->%s", G.vexs[minPath[i1]].name);
    }
    printf("\t距离：%d\n", D[end]);
}
void dfs(MGraph g, int a, int b) {//深搜结束
    int i;
    if (a == b) {
        for (i = 0; i < top; i++)
            printf("%s->", g.vexs[stack[i] - 1].name);//利用栈来存储一条路径的每个结点的位置坐标
        printf("%s", g.vexs[stack[i] - 1].name);
        printf("\n");
        return;
    }
    for (i = 1; i <= g.numVertexes; i++) {
        if (g.arc[a][i] != 0 && g.arc[a][i] != INFINITY && visited[i] == 0) {//如果两个景点之间存在直接的距离连通（两点不重合，两点连通，而且没有别走过）
            visited[i] = 1;//来保证该节点已经走过了
            stack[++top] = g.vexs[i].num;//栈每次向上走，每一层存储响应结点的序号
            dfs(g, i, b);//递归深搜
            top--;
            visited[i] = 0;
        }
    }
}
int showAllPath(MGraph g) {//显示所有路径
    ///输入名称是精确名称
    int a, b, i;
    char str1[MAxVex], str2[MAxVex];
    printf("请输入起点\n");
    scanf("%s", str1);
    a = finVex(str1, g);
    if (a == -1){
        printf("匹配失败，请重新输入！！！\n");
        return -1;
    }
    printf("请输入终点\n");
    scanf("%s", str2);
    b = finVex(str2, g);
    if (b == -1){
        printf("匹配失败，请重新输入！！！\n");
        return -1;
    }
    visited[a] = 1;
    stack[++top] = g.vexs[a].num;
    dfs(g, a, b);
    top = -1; //将栈和visited数组初始化
    for (i = 1; i <= g.numVertexes; i++)
        visited[i] = 0;
}
void floyd(MGraph *g) {//弗洛伊德算法（插点法）
    int v, w, k;
    for (v = 0; v < g->numVertexes; v++)
        for (w = 0; w < g->numVertexes; w++)
            if (g->arc[v][w] == 0 || g->arc[v][w] == INFINITY)
                edge2[v][w] = g->arc[v][w];//将两个点初始化
            else
                edge2[v][w] = 1;//若两个点连通则，为1
    for (v = 0; v < g->numVertexes; v++) {
        for (w = 0; w < g->numVertexes; w++) {
            d1[v][w] = edge2[v][w];//将d1初始化
            p1[v][w] = w;
        }
    }
    for (k = 0; k < g->numVertexes; k++) {
        for (v = 0; v < g->numVertexes; v++) {
            for (w = 0; w < g->numVertexes; w++) {
                if (d1[v][w] > d1[v][k] + d1[k][w]) {//
                    d1[v][w] = d1[v][k] + d1[k][w];
                    p1[v][w] = p1[v][k];
                }
            }
        }
    }
}
void showBestPath(MGraph g) {
    int a, b, k;
    char str1[MAxVex], str2[MAxVex];
    printf("请输入起点\n");
    scanf("%s", str1);
    a = finVex(str1, g);
    if (a == -1)
        return;
    printf("请输入终点\n");
    scanf("%s", str2);
    b = finVex(str2, g);
    if (b == -1)
        return;
    k = p1[a][b];
    printf("%s->", g.vexs[a].name);
    while (k != b) {
        printf("%s->", g.vexs[k].name);
        k = p1[k][b];//保证每一个k值（确认结点最少）
    }
    printf("%s\n", g.vexs[b].name);
}
void chaxun(MGraph G){
    int num,number,i;
    char MAX[100];
    printf("————————————————————————————————————————————\n");
    printf("1.序号查询\n");
    printf("2.名称查询\n");
    printf("3.返回\n");
    printf("————————————————————————————————————————————\n");
    printf("请输入您将选择的序号:\n");
    scanf("%d",&num);
    if(num==1){
        printf("请输入需要查询的序号:\n");
        scanf("%d",&number);
        for(i=0;i<G.numVertexes;i++){
            if(number==G.vexs[i].num){
                printf("%03d\t%10s\t%s\n", G.vexs[i].num, G.vexs[i].name, G.vexs[i].info);
                break;
            }
        }
        getchar();
        chaxun(G);
    }else if(num==2){
        printf("请输入需要查询的名称:\n");
        scanf("%s",MAX);
        for(i=0;i<G.numVertexes;i++){
            if(strcmp(MAX,G.vexs[i].name)==0){
                printf("%03d\t%10s\t%s\n", G.vexs[i].num, G.vexs[i].name, G.vexs[i].info);
                break;
            }
        }
        getchar();
        chaxun(G);
    }else if(num==3){
        menu();
        return ;
    }else{
        printf("输入有误请重新输入!!!\n");
        chaxun(G);
    }
}