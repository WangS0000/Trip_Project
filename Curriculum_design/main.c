#include <stdio.h>//����5��
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAxVex 100//�������Ƶĸ���
#define INFINITY 65535
typedef struct {//����ṹ��Ĵ�������
    int num;//����ÿ����ַ�����
    char name[MAxVex];//��������
    char info[MAxVex];//������
} Ding;//�ṹ����������
typedef struct {//����ͼ��ʵ�ֹ���
    Ding vexs[MAxVex];//����ṹ������
    int arc[MAxVex][MAxVex];//�ö�ά��������ʾÿ���ṹ����ͼ�е�λ��
    int numVertexes, numEdges;
} MGraph;
struct e{
    char a[10];
    char b[10];
}z;//�������Ա�û����Լ�����
int stack[100]; //����2����Ҫ��ȫ�ֱ���
int top = -1;//��ʼ��ջ
int num;
int visited[100] = {0};
int edge2[100][100]; //����3����Ҫ��ȫ�ֱ���
int p1[100][100], d1[100][100];
void floyd(MGraph *g);//
void showBestPath(MGraph g);//���·��
void CreateMGraph(MGraph *G);//�ļ���ʼ��
int finVex(char vex[], MGraph G);//�Ծ����λ������
void showShortestPath(MGraph G);//��ʾ���·��
void Dijkstra(MGraph G, int start, int end);//�Ͻ�˹����
void showAll(MGraph G);//��ʾ����·��
void menu();
void menuOperation(MGraph G);//���˵���ѡ��
int showAllPath(MGraph g);
void dfs(MGraph g, int a, int b);
void menu2();
void guan(MGraph G);
void chaxun(MGraph G);
//void mima();
int main() {
    MGraph G;//��ʼ���ṹ��
    CreateMGraph(&G);//��ȡ�ļ���Ϣ�������ļ����ݳ�ʼ��������������������������������������������Ҫ��������Ϲ���ԱȨ���޸ģ���ӣ�ɾ����Ϣ
    menuOperation(G);
    return 0;
}
void menu() {
    printf("\t\t �������������������������������������������ʵ���ϵͳ������������������������������������ \n");
    printf("\t\t*\t\t 1. ��ѯ���о������ϸ��Ϣ                     \n");
    printf("\t\t*\t\t 2. ��ѯ��������֮�������·��                 \n");
    printf("\t\t*\t\t 3. ��ѯ��������֮������·��                 \n");
    printf("\t\t*\t\t 4. ��ѯ��������֮������·��                 \n");
    printf("\t\t*\t\t 5. �˳�����                                  \n");
    printf("\t\t*\t\t 6. ����Ա��¼                                \n");
    printf("\t\t*\t\t 7. ��ѯ��Ϣ                                  \n");
    printf("\t\t����������������������������������������������������������������������������������������������������\n");
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
        printf("��ǰ�޹���Ա������\n");
        printf("��������Ҫע��Ĺ���Ա��Ϣ��\n");
        printf("����������ע��Ĺ���Ա�û���:\n");
        scanf("%s",s);
        printf("");
        printf("�����ù���Ա���룺\n");
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
        printf("\n�������������룺\n");
        a[i]=getch();
        printf("%c",a[i]);
        while(a[i]!='n'){
            i=i+1;
            a[i]=getch();
            printf("%c",a[i]);
        }
        a[i]='\0';
        printf("���Խ��:\n");
        printf(a);
        printf("\n");
        printf(d);
        printf("\n");*/
        scanf("%s",d);
        printf("������ȷ�Ϲ���Ա���룺\n");
        scanf("%s",a);
        if(!strcmp(a,d)){
            strcpy(z.a,s);
            strcpy(z.b,d);
            fprintf(p,"%s %s",z.a,z.b);
            fclose(p);
            printf("\n����Աע��ɹ�!!!\n");
            printf("�����µ�¼!!!\n");
            menu();
        }else{
            printf("\n�������벻һ��������ע��!!!\n");
            printf("���������룡����\n");
            guan(G);
        }
    }
    if(t==0){
        printf("�������û���:\n");
        scanf("%s",s);
        fscanf(p,"%s %s",z.a,z.b);
        fclose(p);
        if(!strcmp(z.a,s)){
            printf("\n���������룺(��n������)\n");
            //printf("");
            d[j]=getch();
            printf("*");
            while(d[j]!='n')//���ܳ���
            {
                j=j+1;
                d[j]=getch();
                printf("*");
            }
            d[j]='\0';
            //getchar();
            if(!strcmp(z.b,d)){
                printf("����������ȷ!\n");
                printf("�����������Ա����!\n");
                getchar();
                //system("cls");
                menu2();
                printf("����������ѡ������:\n");
                scanf("%d",&num);
                if(num>0&&num<7){
                    /*printf("��Ǹ��Ŀǰ��������δ���ţ�����\n");
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
                        printf("�����뽫Ҫ��ӵľ�����Ϣ:\n");
                        printf("�����뾰�����:\n");
                        scanf("%d",&number);
                        printf("�����뾰������:\n");
                        scanf("%s",Name);
                        printf("�����뾰����:\n");
                        scanf("%s",introduction);
                        printf("�������·��:\n");
                        printf("���������:\n");
                        scanf("%s",loads);
                        printf("�������յ�:\n");
                        scanf("%s",loadss);
                        printf("��������볤��:\n");
                        scanf("%d",loadsss);
                        G.numVertexes=G.numVertexes+1;
                        G.numEdges=G.numEdges+1;
                        fprintf(fp,"\n");
                        fprintf(fp,"%d %s %s",number,Name,introduction);
                        fprintf(first,"%d",G.numVertexes);
                        fprintf(file,"\n");
                        fprintf(file,"%s %s %d",loads,loadss,loadsss);
                        fprintf(end,"%d",G.numEdges);
                        CreateMGraph(&G);///������
                        fclose(fp);
                        fclose(first);
                        fclose(file);
                        fclose(end);
                        //���³�ʼ��
                    }else if(num==2){
                        printf("��ѡ��Ҫ�޸ĵľ�����Ϣ:\n");
                    }else if(num==3){
                        printf("�����뽫Ҫɾ���ľ�����Ϣ:\n");
                    }else if(num==4){
                        printf("�����뽫Ҫ�޸�·�����ȵ���������Ϣ:\n");
                    }else if(num==5){
                        FILE *p;
                        char admin[100];
                        char secrets[100];
                        printf("���޸Ĺ���Ա��Ϣ:\n");
                        printf("���������Ա�û�����\n");
                        scanf("%s",admin);
                        printf("���������Ա���룺\n");
                        scanf("%s",secrets);
                        p=fopen("d:\\guanli.txt","w+");
                        fprintf(p,"%s %s",admin,secrets);
                        fclose(p);
                        printf("�����޸ĳɹ�������\n");
                        printf("�������س��������棡����\n");
                    }else if(num==6){
                        menu();
                        return ;
                    }else{
                        printf("�������󣡣���\n");
                        printf("���ڷ�����ҳ��......");
                        getchar();
                        menu();
                        return;
                    }
                }else{
                    printf("�������󣡣���");
                    printf("����������ҳ��!!!\n");
                    menu();
                    return;
                }
            }else{
                // system("cls");
                printf("\n\n\n\n\n\n");
                printf("�����������!\n");
                printf("����������ҳ��\n");
                getchar();
                menu();
            }
        }
        else{
            //system("cls");
            //printf("\n\n\n\n\n\n\n\n\n\n\n");
            printf("\n\n\n");
            printf("�û�������!\n");
            getchar();
            getchar();
            menu();
        }
    }
}
void menu2(){
    printf("\t\t��������������������������������������������Ա���桪������������������������������������������\n");
    printf("\t\t*\t\t 1.��Ӿ�����Ϣ\n");
    printf("\t\t*\t\t 2.�޸ľ�����Ϣ\n");
    printf("\t\t*\t\t 3.ɾ��������Ϣ\n");
    printf("\t\t*\t\t 4.�޸ľ���·������\n");
    printf("\t\t*\t\t 5.�޸Ĺ���Ա��Ϣ\n");
    printf("\t\t*\t\t 6.�˳�\n");
    printf("\t\t___________________________________________________\n");
}
void menuOperation(MGraph G){
    int x;
    menu();
    printf("����������ѡ�����ţ�\n");
    scanf("%d",&x);
    while(x!=5){
        if(x>7||x<1){
            //system("cls");
            printf("������������������!!!\n");
            printf("����������Ҫѡ�����ţ�\n");
            //menu();
            scanf("%d",&x);
        }else{
            if(x==1){
                system("��ͼ.png");
                showAll(G);
                fflush(stdin);
                //getchar();
                printf("����������ѡ�����ţ�\n");
            }else if (x==2){
                showAllPath(G);
                fflush(stdin);
                //getchar();
                printf("����������ѡ�����ţ�\n");
            }else if(x==3){
                floyd(&G);
                showBestPath(G);
                fflush(stdin);
                //getchar();
                printf("����������ѡ�����ţ�\n");
            }else if(x==4){
                showShortestPath(G);
                fflush(stdin);
                //getchar();
                printf("����������ѡ�����ţ�\n");
            }else if(x==6){
                //�ù���δ���
                // printf("�������δ����\n");
                // printf("�����ڴ�");
                ///menu2();
                guan(G);
                CreateMGraph(&G);
                //getchar();
                //menu();
                printf("����������ѡ�����ţ�\n");
            }else if(x==7){
                chaxun(G);
                //printf("����������ѡ�����ţ�\n");
            }
            //system("cls");
            //menu();
            // printf("����������ѡ�����ţ�\n");
            scanf("%d",&x);
            getchar();
        }
    }
    if(x==5){
        printf("���н���\n");
        exit(0);
    }
}
void showAll(MGraph G) {
    int i;
    for (i = 0 ; i < G.numVertexes ; i++) {//����G.numVertexes����Ϣ
        printf("%03d\t%10s\t%s\n", G.vexs[i].num, G.vexs[i].name, G.vexs[i].info);///��ӡÿ����Ϣ����ϸ��Ϣ
    }
    printf("\n");
}
void CreateMGraph(MGraph *G) {//��ȡ�ļ����г�ʼ��
    int i, j, w, x, y;
    char vex1[100], vex2[100];
    FILE *fp;//�����ļ�ָ��
    FILE *file;
    FILE *first;
    FILE *end;
    if ((fp = fopen("d:\\school.txt","r")) == NULL) {//��ֻ���ķ�ʽ��ȡ�ļ�
        printf("�ļ��򿪳���!!!\n");
        printf("�쳣�˳�������\n");
        exit(1);//��ʾ�쳣�˳�������1��˼�ǣ�ϵͳ���صı�����Ϣ������1
    }
    if((file = fopen("d:\\schools.txt","r"))==NULL){
        printf("���ļ�����!!!\n");
        printf("�쳣�˳�������\n");
        exit(1);//��ʾ�쳣�˳�������1��˼�ǣ�ϵͳ���صı�����Ϣ������1
    }
    if ((first = fopen("d:\\first.txt","r")) == NULL) {//��ֻ���ķ�ʽ��ȡ�ļ�
        printf("�ļ��򿪳���!!!\n");
        printf("�쳣�˳�������\n");
        exit(1);//��ʾ�쳣�˳�������1��˼�ǣ�ϵͳ���صı�����Ϣ������1
    }
    if ((end = fopen("d:\\end.txt","r")) == NULL) {//��ֻ���ķ�ʽ��ȡ�ļ�
        printf("�ļ��򿪳���!!!\n");
        printf("�쳣�˳�������\n");
        exit(1);//��ʾ�쳣�˳�������1��˼�ǣ�ϵͳ���صı�����Ϣ������1
    }
    fscanf(first, "%d", &G->numVertexes);
    fscanf(end,"%d", &G->numEdges);
    for (i = 0; i < G->numVertexes; i++) {//�ļ���Ϣ������������Ϣ��������Ҳ����˵�Ƕ�ȡ����
        fscanf(fp, "%d %s %s", &G->vexs[i].num, G->vexs[i].name, G->vexs[i].info);//���ļ��е�����д��ϵͳ
    }//ѭ����ȡ
    ///Ϊͼ��׼��
    for (i = 0; i < G->numVertexes; i++) {//���������ö�ά���齫ÿ��λ�ö�������ֵ
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;//ÿ���㶼���������ֵ
        G->arc[i][i] = 0;//�������εĴ������ҶԽ��߱�����ֵ0
    }
    for (i = 0; i < G->numEdges; i++) {
        fgetc(file); // ���� "\n"
        fgetc(file); // ���� "<"
        fscanf(file, "%s %s %d", vex1, vex2, &w);//����λ����Ϣ�Լ���λ�õľ����������
        ///����λ������
        x = finVex(vex1, *G);
        y = finVex(vex2, *G);
        ///�������еĲ������������ľ�����ֵ
        G->arc[x][y] = w;
        G->arc[y][x] = w;
        fgetc(file); // ���� ">"
    }
    fclose(fp);
    fclose(file);
    fclose(first);
    fclose(end);
}
int finVex(char vex[], MGraph G) {//����ƥ������ص���Ϣ����Ӧ��λ������
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
    printf("���������\n");
    scanf("%s", str1);
    start = finVex(str1, G);
    if (start == -1)
        return;
    printf("�������յ�\n");
    scanf("%s", str2);
    end = finVex(str2, G);
    if (end == -1)
        return;
    Dijkstra(G, start, end);
}
void Dijkstra(MGraph G, int start, int end) {//�Ͻ�˹�����㷨
    int v, w,i1, k = 0, min;
    int temp = end;
    int minPath[MAxVex];
    int count=1;
    int path[MAxVex], D[MAxVex]; //P[v]��ֵΪǰ�������±꣬D[v]��ʾv0��v�����·�����Ⱥ�
    int final[MAxVex]; //final[w] = 1��ʾ��Ķ���v0��vw�����·��
    for (v = 0; v < G.numVertexes; v++) {//��ʼ��ʼ��
        final[v] = 0;
        D[v] = G.arc[start][v];//����
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
    printf("\t���룺%d\n", D[end]);
}
void dfs(MGraph g, int a, int b) {//���ѽ���
    int i;
    if (a == b) {
        for (i = 0; i < top; i++)
            printf("%s->", g.vexs[stack[i] - 1].name);//����ջ���洢һ��·����ÿ������λ������
        printf("%s", g.vexs[stack[i] - 1].name);
        printf("\n");
        return;
    }
    for (i = 1; i <= g.numVertexes; i++) {
        if (g.arc[a][i] != 0 && g.arc[a][i] != INFINITY && visited[i] == 0) {//�����������֮�����ֱ�ӵľ�����ͨ�����㲻�غϣ�������ͨ������û�б��߹���
            visited[i] = 1;//����֤�ýڵ��Ѿ��߹���
            stack[++top] = g.vexs[i].num;//ջÿ�������ߣ�ÿһ��洢��Ӧ�������
            dfs(g, i, b);//�ݹ�����
            top--;
            visited[i] = 0;
        }
    }
}
int showAllPath(MGraph g) {//��ʾ����·��
    ///���������Ǿ�ȷ����
    int a, b, i;
    char str1[MAxVex], str2[MAxVex];
    printf("���������\n");
    scanf("%s", str1);
    a = finVex(str1, g);
    if (a == -1){
        printf("ƥ��ʧ�ܣ����������룡����\n");
        return -1;
    }
    printf("�������յ�\n");
    scanf("%s", str2);
    b = finVex(str2, g);
    if (b == -1){
        printf("ƥ��ʧ�ܣ����������룡����\n");
        return -1;
    }
    visited[a] = 1;
    stack[++top] = g.vexs[a].num;
    dfs(g, a, b);
    top = -1; //��ջ��visited�����ʼ��
    for (i = 1; i <= g.numVertexes; i++)
        visited[i] = 0;
}
void floyd(MGraph *g) {//���������㷨����㷨��
    int v, w, k;
    for (v = 0; v < g->numVertexes; v++)
        for (w = 0; w < g->numVertexes; w++)
            if (g->arc[v][w] == 0 || g->arc[v][w] == INFINITY)
                edge2[v][w] = g->arc[v][w];//���������ʼ��
            else
                edge2[v][w] = 1;//����������ͨ��Ϊ1
    for (v = 0; v < g->numVertexes; v++) {
        for (w = 0; w < g->numVertexes; w++) {
            d1[v][w] = edge2[v][w];//��d1��ʼ��
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
    printf("���������\n");
    scanf("%s", str1);
    a = finVex(str1, g);
    if (a == -1)
        return;
    printf("�������յ�\n");
    scanf("%s", str2);
    b = finVex(str2, g);
    if (b == -1)
        return;
    k = p1[a][b];
    printf("%s->", g.vexs[a].name);
    while (k != b) {
        printf("%s->", g.vexs[k].name);
        k = p1[k][b];//��֤ÿһ��kֵ��ȷ�Ͻ�����٣�
    }
    printf("%s\n", g.vexs[b].name);
}
void chaxun(MGraph G){
    int num,number,i;
    char MAX[100];
    printf("����������������������������������������������������������������������������������������\n");
    printf("1.��Ų�ѯ\n");
    printf("2.���Ʋ�ѯ\n");
    printf("3.����\n");
    printf("����������������������������������������������������������������������������������������\n");
    printf("����������ѡ������:\n");
    scanf("%d",&num);
    if(num==1){
        printf("��������Ҫ��ѯ�����:\n");
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
        printf("��������Ҫ��ѯ������:\n");
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
        printf("������������������!!!\n");
        chaxun(G);
    }
}