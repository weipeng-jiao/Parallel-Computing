#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
    double star1=omp_get_wtime();
    int cpu_nums = omp_get_num_procs();//获得处理器数量
    int max_threads = omp_get_max_threads();//获得并行区最大线程数
    cout<<"核数是："<<cpu_nums<<endl<<"最大线程数量是："<<max_threads<<endl;
    int live1 = omp_in_parallel();
        if(live1 != 0)
        {
            cout<<"在并行区"<<endl;
        }
        else
        {
            cout<<"不在并行区"<<endl;
        }
    #pragma omp parallel num_threads(6)
    {
        double star=omp_get_wtime();
        int live2 = omp_in_parallel();
        if(live2 != 0)
        {
            cout<<"在并行区"<<endl;
        }
        else
        {
            cout<<"不在并行区"<<endl;
        }
        int num = omp_get_thread_num();//获得线程编号
        int live_max_threads = omp_get_max_threads();//获得并行区最大线程数
        double end=omp_get_wtime();
        cout <<"线程计算时间:"<<star-end<<endl<<"并行区最大线程数："<<live_max_threads <<endl <<"task is "<< num <<endl;
    }
    double end1=omp_get_wtime();
    cout<<"总的运行时间："<<star1-end1<<endl;
    return 0;
}
