#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/pwm.h>

struct dw_pwm_chip {
    struct pwm_chip chip;

};




//#ifdef CONFIG_OF
static const struct of_device_id    dw_pwm_of_match[] = {
    { .compatible = "ti,twl4030-pwm" },
    { .compatible = "ti,twl6030-pwm" },
    { },
};
MODULE_DEVICE_TABLE(of, dw_pwm_of_match);
//#endif

static int dw_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{

}

static void dw_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{

}

static int dw_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
		int duty_ns, int period_ns)
{

}

static int dw_set_polarity(struct pwm_chip *chip,
				   struct pwm_device *pwm,
				   enum pwm_polarity polarity)
{


}


static struct pwm_ops dw_pwm_ops = {
    .enable = dw_pwm_enable,
    .disable = dw_pwm_disable,
    .config = dw_pwm_config,
    .set_polarity = dw_set_polarity,
    .owner = THIS_MODULE,
};

static int design_pwm_probe(struct platform_device *pdev)
{
    struct dw_pwm_chip *dw_pwm_st = NULL;
    int ret = 0;

    dw_pwm_st = devm_kzalloc(&pdev->dev, sizeof(struct dw_pwm_chip), GFP_KERNEL);
    if (!dw_pwm_st) {
        dev_err(&pdev->dev, "malloc mem for dev failed.\n");
        return -ENOMEM;
    }

    dw_pwm_st->chip.dev = &pdev->dev;
    dw_pwm_st->chip.base = -1;
    dw_pwm_st->chip.ops = &dw_pwm_ops;

    ret = pwmchip_add(&dw_pwm_st->chip);
    if (ret < 0) {
        dev_err(&pdev->dev, "add pwm chip failed.\n");
        return ret;
    }

	platform_set_drvdata(pdev, dw_pwm_st);
    return ret;
}

static int design_pwm_remove(struct platform_device *pdev)
{
    struct dw_pwm_chip *dw_pwm_st = platform_get_drvdata(pdev);

    return pwmchip_remove(&dw_pwm_st->chip);
}


static struct platform_driver designware_pwm_driver = {
    .driver =  {
        .name = "designware-pwm",
        .of_match_table = dw_pwm_of_match,
    },
    .probe = design_pwm_probe,
    .remove = design_pwm_remove,
};


module_platform_driver(designware_pwm_driver);

MODULE_DESCRIPTION("PWM driver for designware");
MODULE_AUTHOR("wei.cheng@bitmain.com");
MODULE_LICENSE("GPL v2");


