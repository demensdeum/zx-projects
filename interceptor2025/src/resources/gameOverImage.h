
/* png2c.py 1.4.1
 *
 * gameOver.png (256x192)
 * 32 x 24 (57 unique)
 *
 * base: 128
 */

unsigned char gameOverImage_ptiles[] = {
    0x14, 0x00, 0x0e, 0x20, 0x80, 0x0f, 0x0d, 0x0e,
    0x20, 0x80, 0x0f, 0x0d, 0x0e, 0x20, 0x80, 0x0f,
    0x0d, 0x0e, 0x20, 0x80, 0x0f, 0x0d, 0x0e, 0x20,
    0x80, 0x0f, 0x0d, 0x0e, 0x20, 0x80, 0x0f, 0x0d,
    0x0e, 0x06, 0x80, 0x0f, 0x14, 0x41, 0x81, 0x82,
    0x82, 0x83, 0x84, 0x85, 0x82, 0x82, 0x82, 0x82,
    0x86, 0x87, 0x82, 0x82, 0x88, 0x82, 0x82, 0x82,
    0x82, 0x89, 0x14, 0x00, 0x0e, 0x06, 0x80, 0x0f,
    0x0d, 0x0e, 0x06, 0x80, 0x0f, 0x14, 0x41, 0x8a,
    0x14, 0x4f, 0x8b, 0x14, 0x79, 0x8c, 0x14, 0x4f,
    0x8d, 0x14, 0x79, 0x8e, 0x14, 0x4f, 0x8f, 0x14,
    0x79, 0x90, 0x91, 0x14, 0x4f, 0x92, 0x14, 0x79,
    0x93, 0x14, 0x48, 0x94, 0x14, 0x41, 0x95, 0x14,
    0x79, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b, 0x9c,
    0x14, 0x48, 0x95, 0x14, 0x00, 0x0e, 0x06, 0x80,
    0x0f, 0x0d, 0x0e, 0x06, 0x80, 0x0f, 0x14, 0x41,
    0x9d, 0x14, 0x4f, 0x9e, 0x9f, 0xa0, 0xa1, 0xa2,
    0xa3, 0xa4, 0x14, 0x79, 0xa5, 0xa6, 0x14, 0x48,
    0x94, 0x14, 0x41, 0xa7, 0x14, 0x79, 0xa8, 0xa9,
    0xaa, 0xab, 0xac, 0x14, 0x4f, 0xad, 0xae, 0x14,
    0x48, 0xaf, 0x14, 0x00, 0x0e, 0x06, 0x80, 0x0f,
    0x0d, 0x0e, 0x07, 0x80, 0x0f, 0x14, 0x48, 0xb0,
    0xb1, 0xb1, 0xb1, 0xb1, 0xb2, 0xb3, 0xb1, 0xb4,
    0xb5, 0x14, 0x41, 0x9d, 0x14, 0x48, 0xb1, 0xb6,
    0xb0, 0xb7, 0xb1, 0xb1, 0xb1, 0xb8, 0x14, 0x00,
    0x0e, 0x06, 0x80, 0x0f, 0x0d, 0x0e, 0x20, 0x80,
    0x0f, 0x0d, 0x0e, 0x20, 0x80, 0x0f, 0x0d, 0x0e,
    0x20, 0x80, 0x0f, 0x0d, 0x0e, 0x20, 0x80, 0x0f,
    0x0d, 0x0e, 0x20, 0x80, 0x0f, 0x0d, 0x0e, 0x20,
    0x80, 0x0f, 0x0d, 0x0e, 0x20, 0x80, 0x0f, 0x0d,
    0x0e, 0x20, 0x80, 0x0f, 0x0d, 0x0e, 0x20, 0x80,
    0x0f, 0x0d, 0x0e, 0x20, 0x80, 0x0f, 0x0d, 0x0e,
    0x20, 0x80, 0x0f, 0x0d, 0x0e, 0x20, 0x80, 0x0f,
    0x0d, 0x0e, 0x20, 0x80, 0x0f, 0x0d, 0x0e, 0x20,
    0x80, 0x0f, 0x0d, 0x00
};

#define GAME_OVER_IMAGE_TILES_BASE 128
#define GAME_OVER_IMAGE_TILES_LEN 57
unsigned char gameOverImage_tiles[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // y:0, x:0 (128)
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, // y:6, x:6 (129)
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, // y:6, x:7 (130)
    0x00, 0x00, 0x00, 0x00, 0x07, 0x8f, 0x8f, 0x8f, // y:6, x:9 (131)
    0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xfc, 0xfc, // y:6, x:10 (132)
    0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, // y:6, x:11 (133)
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, // y:6, x:16 (134)
    0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, // y:6, x:17 (135)
    0x00, 0x00, 0x00, 0x00, 0xe7, 0xff, 0xff, 0xff, // y:6, x:20 (136)
    0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, // y:6, x:25 (137)
    0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, // y:7, x:6 (138)
    0x7f, 0x7f, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x7e, // y:7, x:7 (139)
    0x03, 0x03, 0x07, 0xff, 0xff, 0xff, 0x81, 0x01, // y:7, x:8 (140)
    0x01, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, // y:7, x:9 (141)
    0x1f, 0x1f, 0x0f, 0x07, 0x07, 0x87, 0x83, 0xc3, // y:7, x:10 (142)
    0x1f, 0x1f, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, // y:7, x:11 (143)
    0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, // y:7, x:12 (144)
    0x00, 0x00, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, // y:7, x:13 (145)
    0x3f, 0x3f, 0x3e, 0x3e, 0x3e, 0xbe, 0xbf, 0xbf, // y:7, x:14 (146)
    0x01, 0x03, 0xe7, 0xff, 0xff, 0xff, 0x43, 0x01, // y:7, x:15 (147)
    0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, // y:7, x:16 (148)
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, // y:7, x:17 (149)
    0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, // y:7, x:18 (150)
    0x0c, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, // y:7, x:19 (151)
    0x3e, 0x3c, 0x1c, 0x1c, 0x18, 0x18, 0x08, 0x00, // y:7, x:20 (152)
    0x18, 0x38, 0x38, 0x38, 0x38, 0x78, 0x78, 0x78, // y:7, x:21 (153)
    0x00, 0x00, 0x70, 0x7f, 0x7f, 0x7f, 0x60, 0x00, // y:7, x:22 (154)
    0x60, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, // y:7, x:23 (155)
    0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xa0, 0x80, // y:7, x:24 (156)
    0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, // y:8, x:6 (157)
    0x3c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1f, 0x1f, 0x1f, // y:8, x:7 (158)
    0x7e, 0x3e, 0x3e, 0x3e, 0x3e, 0xfe, 0xfe, 0xfe, // y:8, x:8 (159)
    0x1e, 0x1e, 0x3c, 0x3c, 0x3c, 0x3c, 0x78, 0x78, // y:8, x:9 (160)
    0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0xff, 0xff, 0xff, // y:8, x:10 (161)
    0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1c, // y:8, x:11 (162)
    0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, // y:8, x:12 (163)
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // y:8, x:13 (164)
    0x00, 0x01, 0x01, 0x43, 0xc3, 0xc0, 0x40, 0xe0, // y:8, x:14 (165)
    0x01, 0xff, 0xff, 0xff, 0xff, 0x03, 0x03, 0x03, // y:8, x:15 (166)
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03, // y:8, x:17 (167)
    0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x00, 0x80, 0x80, // y:8, x:18 (168)
    0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, // y:8, x:19 (169)
    0x00, 0x80, 0x81, 0x81, 0x81, 0xc1, 0xc1, 0xe1, // y:8, x:20 (170)
    0x78, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, // y:8, x:21 (171)
    0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, // y:8, x:22 (172)
    0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1e, // y:8, x:23 (173)
    0x7c, 0x78, 0x38, 0x38, 0x1c, 0x1e, 0x1e, 0x0e, // y:8, x:24 (174)
    0x1f, 0x3f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, // y:8, x:25 (175)
    0x00, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, // y:9, x:7 (176)
    0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, // y:9, x:8 (177)
    0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, // y:9, x:12 (178)
    0x00, 0x00, 0x20, 0xff, 0xff, 0xff, 0xff, 0xff, // y:9, x:13 (179)
    0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, // y:9, x:15 (180)
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, // y:9, x:16 (181)
    0x00, 0x03, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, // y:9, x:19 (182)
    0x00, 0x00, 0x60, 0xff, 0xff, 0xff, 0xff, 0xff, // y:9, x:21 (183)
    0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, // y:9, x:25 (184)
};

