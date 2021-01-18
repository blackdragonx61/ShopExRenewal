//Find
	SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX,
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM,
	SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP,
#endif

//Find in : packet_shop_item
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	BYTE 	price_type;
	DWORD 	price_vnum;
	packet_shop_item() : price_type(SHOPEX_GOLD), price_vnum(0) {
		memset(&alSockets, 0, sizeof(alSockets));
		memset(&aAttr, 0, sizeof(aAttr));
	}
#endif