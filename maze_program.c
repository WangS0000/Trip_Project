#include <stdio.h>
#define MaxSize 100
#define M 8
#define N 8
int mg[M+2][N+2]=
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};//�����ͼ
typedef struct
{
    int i;              //��ǰ������к�
    int j;              //��ǰ������к�
    int di;             //di����һ�������ڷ�λ�ķ�λ��---�������ҵı��
} Box;
typedef struct
{
    Box data[MaxSize];	//�������洢λ������ģ���MaxSize<λ���������Ŀʱ����������ֹͣ����
    int top;            //ջ��ָ��
} StType;               //����ջ����
//��ջ��:ÿһ��λ�����ڴ洢Box����ջ��Ӧ��һ��int�͵�top��Ϊָ�룬�����ƶ��������ջ��ÿһ��λ�ý��в�������Box�У��洢�˸��Թ�λ�õĺ����꣬�����꣬�ʹ���һλ���ƶ�����λ������Ӧ�ķ�����ֵ

int mgpath(int xi,int yi,int xe,int ye) //���·��Ϊ:(xi,yi)->(xe,ye)
		   //��λ�ú����꣬��λ�������꣬�յ�����꣬�յ�������
{
    int i,j,k,di,find;
    StType st;                  //����ջst
    st.top=-1;                  //��ʼ��ջ��ָ��
    st.top++;                   //��ʼ�����ջ
    st.data[st.top].i=xi;//ջ��һ�Ŵ����������ֵ
    st.data[st.top].j=yi;//ջ��һ�Ŵ�����������ֵ
    st.data[st.top].di=-1;//????????????????????????????????
    mg[xi][yi]=-1;
    while (st.top>-1)           //ջ����ʱѭ��
    {
        i=st.data[st.top].i;
        j=st.data[st.top].j;
        di=st.data[st.top].di;  //ȡջ������
        if (i==xe && j==ye)     //�ҵ��˳���,���·��
        {
            printf("�Թ�·������:\n");
            for (k=0; k<=st.top; k++)
            {
                printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
                if ((k+1)%5==0) //ÿ���5��Ԫ�أ��ͻ���
                    printf("\n");
            }
            printf("\n");
            return 0;      //�ҵ�·��֮�󣬽�����·����ӡ������Ȼ�󣬳������
        }
        find=0;
        while (di<4 && find==0)     //����һ�����߷���
        {
            di++;
            switch(di)
            {
            case 0://������
                i=st.data[st.top].i-1;
                j=st.data[st.top].j;
                break;
            case 1://������
                i=st.data[st.top].i;
                j=st.data[st.top].j+1;
                break;
            case 2://������
                i=st.data[st.top].i+1;
                j=st.data[st.top].j;
                break;
            case 3://������
                i=st.data[st.top].i;
				j=st.data[st.top].j-1;
                break;
            }
            if (mg[i][j]==0) find=1;    //mg[i][j]==0˵��:�õ������--------------(�õ�Ϊ��ʱ���ڵ����һԤ�е�)
        }
        if (find==1)                    //�ҵ�����һ�����߷���
        {
            st.data[st.top].di=di;      //�޸�ԭջ��Ԫ�ص�diֵ
            st.top++;                   //��һ�����߷����ջ
            st.data[st.top].i=i;
            st.data[st.top].j=j;
            st.data[st.top].di=-1;		//�ٴγ�ʼ��������ֵ
            mg[i][j]=-1;                //�����ظ��ߵ��÷���-----------------------//��ÿһ���㶼�����㣬��ˣ�������ݹ��������Ҳ�����ظ��ߵ���λ��
        }
        else                            //û��·������,����ջ-----------����������������������ΪʲôҪ��ջ�����Ǹո�ֻ�ж���һ��������
        {
            mg[st.data[st.top].i][st.data[st.top].j]=0;//�ø�λ�ñ�Ϊ����·�����߷���
            st.top--;                   //���÷�����ջ
        }
    }
    return(0);                          //��ʾû�п���·��,����0
}

int main()
{
	int x,y,k,t;
	printf("�յ�����Ϊ:(8,8)\n");
	while(1){
			printf("�������������:\n");
			printf("(�����귶Χ:0~9,�����귶Χ:0~9)\n");
			scanf("%d %d",&x,&y);
			if(mg[x][y]==1){
			printf("�����������󣬸�λ��Ϊǽ,����������:\n");
			}else{
				break;
			}
	}
	mgpath(x,y,M,N);
	printf("\n\nͼ���ʾ:\n");
	for(t=0;t<10;t++){
		printf("\t\t");
		for(k=0;k<10;k++){
			if(mg[t][k]==1){
				printf("#");
			}else if(mg[t][k]==0){
				printf(" ");
			}else{
				printf("o");
			}
		}
		if(k==10){
			printf("\n");
		}
	}
	printf("\n��ʱ��o�������ͼ��Ϊ�Թ�����·��!!!\n");
    return 0;
}
