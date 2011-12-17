#ifndef _ACER_PICASSO_EC_H
#define _ACER_PICASSO_EC_H

#include <linux/device.h>
#include <linux/i2c.h>
#include <linux/mutex.h>

#define PICASSO_EC_NAME "acer_picasso_ec"
#define PICASSO_EC_ID	PICASSO_EC_NAME
#define PICASSO_EC_BAT_ID "acer_picasso_battery"
#define PICASSO_EC_LED_ID "acer_picasso_leds"

enum picasso_ec_reg {
	EC_BATT_CAPACITY = 0x0,
	EC_BATT_VOLTAGE	= 0x1,
	EC_BATT_DESIGN_CAPACITY = 0x8,
	EC_BATT_TEMPERATURE = 0xa,
};

/**
 * @brief the callback to read a 16-bit word from an ec register
 * @param client the pointer to the i2c_client of the ec chip
 * @param command the register to read
 * @return positive value of the register or negative error code
 */
typedef s32 (*ec_read_cb)(struct i2c_client* client, u8 command);

/**
 * @brief the callback to write a 16-bit word to an ec register
 * @param client the pointer to the i2c_client of the ec chip
 * @param command the register to write
 * @param value the value to write to the register
 * @return positive value of the register or negative error code
 */
typedef s32 (*ec_write_cb)(struct i2c_client*, u8 command, u16 value);

struct acer_picasso_ec_priv {
	struct i2c_client *client;
	struct mutex mutex;
	ec_read_cb read;
	ec_write_cb write;
};

#endif
