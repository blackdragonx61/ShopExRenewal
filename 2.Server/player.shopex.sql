SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for shopex
-- ----------------------------
DROP TABLE IF EXISTS `shopex`;
CREATE TABLE `shopex`  (
  `vnum` int NOT NULL DEFAULT 0,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'Noname',
  `npc_vnum` smallint NOT NULL DEFAULT 0,
  PRIMARY KEY (`vnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of shopex
-- ----------------------------
INSERT INTO `shopex` VALUES (61, 'ARMOR', 9002);
INSERT INTO `shopex` VALUES (62, 'WEAPON', 9002);
INSERT INTO `shopex` VALUES (63, 'TAB3', 9002);
INSERT INTO `shopex` VALUES (64, 'test', 9003);

-- ----------------------------
-- Table structure for shopex_item
-- ----------------------------
DROP TABLE IF EXISTS `shopex_item`;
CREATE TABLE `shopex_item`  (
  `shop_vnum` int NOT NULL DEFAULT 0,
  `item_vnum` int NOT NULL DEFAULT 0,
  `count` tinyint UNSIGNED NOT NULL DEFAULT 1,
  `price` int UNSIGNED NOT NULL DEFAULT 0,
  `price_vnum` int UNSIGNED NOT NULL DEFAULT 0,
  `price_type` enum('GOLD','SECONDCOIN','ITEM','EXP') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'GOLD',
  `socket0` int UNSIGNED NOT NULL DEFAULT 0,
  `socket1` int UNSIGNED NOT NULL DEFAULT 0,
  `socket2` int UNSIGNED NOT NULL DEFAULT 0,
  `attrtype0` tinyint NOT NULL DEFAULT 0,
  `attrvalue0` smallint NOT NULL DEFAULT 0,
  `attrtype1` tinyint NOT NULL DEFAULT 0,
  `attrvalue1` smallint NOT NULL DEFAULT 0,
  `attrtype2` tinyint NOT NULL DEFAULT 0,
  `attrvalue2` smallint NOT NULL DEFAULT 0,
  `attrtype3` tinyint NOT NULL DEFAULT 0,
  `attrvalue3` smallint NOT NULL DEFAULT 0,
  `attrtype4` tinyint NOT NULL DEFAULT 0,
  `attrvalue4` smallint NOT NULL DEFAULT 0,
  `attrtype5` tinyint NOT NULL DEFAULT 0,
  `attrvalue5` smallint NOT NULL DEFAULT 0,
  `attrtype6` tinyint NOT NULL DEFAULT 0,
  `attrvalue6` smallint NOT NULL DEFAULT 0,
  UNIQUE INDEX `vnum_unique`(`shop_vnum`, `item_vnum`, `count`, `price`, `price_vnum`, `price_type`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of shopex_item
-- ----------------------------
INSERT INTO `shopex_item` VALUES (61, 12019, 1, 250, 0, 'GOLD', 0, 0, 0, 0, 0, 1, 2000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `shopex_item` VALUES (61, 12029, 1, 25000, 0, 'GOLD', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `shopex_item` VALUES (62, 299, 1, 5000, 0, 'GOLD', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `shopex_item` VALUES (62, 279, 1, 1, 299, 'ITEM', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `shopex_item` VALUES (63, 19, 1, 13, 0, 'GOLD', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `shopex_item` VALUES (64, 39, 1, 500, 0, 'GOLD', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

SET FOREIGN_KEY_CHECKS = 1;
