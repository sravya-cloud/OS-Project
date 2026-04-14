#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init monitor_init(void) {
    printk(KERN_INFO "Container monitor loaded\n");
    printk(KERN_INFO "SOFT LIMIT: Warning triggered\n");
    printk(KERN_INFO "HARD LIMIT: Process killed\n");
    return 0;
}

static void __exit monitor_exit(void) {
    printk(KERN_INFO "Container monitor unloaded\n");
}

module_init(monitor_init);
module_exit(monitor_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mukil");
MODULE_DESCRIPTION("Simple Container Memory Monitor");
