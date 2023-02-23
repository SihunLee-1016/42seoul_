<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

/* default db settings */

define( 'DB_NAME', getenv('MYSQL_DATABASE') );
define( 'DB_USER', getenv('MYSQL_USER') );
define( 'DB_PASSWORD', getenv('MYSQL_PASSWORD') );
define( 'DB_HOST', 'mariadb' );
define( 'DB_CHARSET', 'utf8' );
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */

/**#@-*/
/* insert keys here */
/* my own key!! */
define('AUTH_KEY',         '@Uh]_(u.{et_Fc+dPVBHlIA(~-F-57qo*3pBu->m)8eP43E aPMO%uZt6C!eH@pH');
define('SECURE_AUTH_KEY',  '%v++y`_,3lC]aZ$pE| +WzoPF|PakKSsv|TQx(fDB@A1S_D{;w3fdA|b&N$b~9U+');
define('LOGGED_IN_KEY',    '$|QAwPVp}R6*[A`sD0-TUDXpcQVzK-yg4X[HWQL[4o5 D^s)8sFn/EeX$5Z(|/#;');
define('NONCE_KEY',        '-?3~P/+0M_<,Oumuyjr[5AUsj+H4606Wg2y8CRxs!k}m@LVs`xs6r,{Jj$y}afRq');
define('AUTH_SALT',        'Rt8Y>dLB*3QFD|?0NdiO)-4mD4Gbv.pe+.--T=X#L]+~>!Z&rLl4QI):czq+I#K.');
define('SECURE_AUTH_SALT', 'JLEQUYdDV*<BqNMm8o?nPw@aG|6=~teO<eZ5v~l+J1.u!hjRQ>0pJZ3KqB2}5|w|');
define('LOGGED_IN_SALT',   '*/4~2$sH*b*;ctmi=8fF|-.ykV(Gl.jr6]H=E-GyTEBVWMUog4i8$!Q6YXy+0qc;');
define('NONCE_SALT',       'UDQ#lAe<_Br;vCpYJZGsTdU<X#o]HX-=[y1<se-gpLAQL&MA`YQ3|H5a %m7?H.Q');
/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
