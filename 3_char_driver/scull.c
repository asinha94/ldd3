#include <linux/init.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
    dev_t dev;
    int result;
    int scull_major = 0;
	printk(KERN_ALERT "Creating Char Driver Scull\n");
    result = alloc_chrdev_region(&dev, 0, 4, "scull");
    scull_major = MAJOR(dev);
    if (result < 0) {
        printk(KERN_WARNING "scull: can't get major %d\n", scull_major);
    }
	return result;
}


static void hello_exit(void)
{
    printk(KERN_ALERT "Goodbye, Cruel World\n");
}

module_init(hello_init);
module_exit(hello_exit);
