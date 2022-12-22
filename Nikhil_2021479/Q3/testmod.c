#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched/signal.h>
MODULE_LICENSE("GPL");

int input_id;
module_param(id,int,S_IRUGO);

static int entry_function(void){
    struct task_struct *t; 
    
    for_each_process(t) {
        
        if(t->pid==input_id){
        printk(KERN_INFO "PID  : %d",t->pid);
        printk(KERN_INFO "UID  : %d",t->cred->uid);
        printk(KERN_INFO "PGID : %d",t->cred->gid);
        return 0;
        }
         
    }
    return 0;
}

static void exit_function(void){
    pr_info("%s: Bye ....\n", __func__);
}

module_init(entry_function);
module_exit(exit_function);
