#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/kobject.h>

struct my_kobj {
	int val;
	struct kobject kobj;
};

struct my_kobj *obj1, *obj2;
struct kobj_type my_type;

struct attribute name_attr = {
	.name = "name",
	.mode = 0444,
};

struct attribute val_attr = {
	.name = "val",
	.mode = 0666,
};

struct attribute *my_attrs[] = {
	&name_attr, 
	&val_attr,
	NULL,
};

ssize_t my_show(struct kobject *kobj, struct attribute *attr, char *buffer)
{
	struct my_kobj *obj = container_of(kobj, struct my_kobj, kobj);
	ssize_t count = 0;

	if (strcmp(attr->name, "name") == 0) {
		count = sprintf(buffer, "%s\n", kobject_name(kobj));
	} else if (strcmp(attr->name, "val") == 0) {
		count = sprintf(buffer, "%d\n", obj->val);
	}

	return count;
}

ssize_t my_store(struct kobject *kobj, struct attribute *attr, const char *buffer, size_t size)
{
	struct my_kobj *obj = container_of(kobj, struct my_kobj, kobj);

	if (strcmp(attr->name, "val") == 0) {
		sscanf(buffer, "%d", &obj->val);
	}

	return size;
}

struct sysfs_ops my_sysfsops = {
	.show = my_show,
	.store = my_store,
};

void obj_release(struct kobject *kobj)
{
	struct my_kobj *obj = container_of(kobj, struct my_kobj, kobj);
	printk(KERN_INFO "obj_release %s\n", kobject_name(&obj->kobj));
	kfree(obj);
}

static int __init mykobj_init(void)
{
	printk(KERN_INFO "mykobj_init\n");

	obj1 = kzalloc(sizeof(struct my_kobj), GFP_KERNEL);
	if (!obj1) {
		return -ENOMEM;
	}
	obj1->val = 1;

	obj2 = kzalloc(sizeof(struct my_kobj), GFP_KERNEL);
	if (!obj2) {
		kfree(obj1);
		return -ENOMEM;
	}
	obj2->val = 2;

	my_type.release = obj_release;
	my_type.default_attrs = my_attrs;
	my_type.sysfs_ops = &my_sysfsops;

	kobject_init_and_add(&obj1->kobj, &my_type, NULL, "mykobj1");
	kobject_init_and_add(&obj2->kobj, &my_type, &obj1->kobj, "mykobj2");

	return 0;
}

static void __exit mykobj_exit(void)
{
	printk(KERN_INFO "mykobj_exit\n");

	kobject_del(&obj2->kobj);
	kobject_put(&obj2->kobj);
	
	kobject_del(&obj1->kobj);
	kobject_put(&obj1->kobj);

	return;
}

module_init(mykobj_init);
module_exit(mykobj_exit);

MODULE_LICENSE("GPL");

