//Find in : SShopItemTable
	BYTE		display_pos;
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	long alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];
	BYTE 	price_type;
	DWORD 	price_vnum;
	SShopItemTable() : price_type(SHOPEX_GOLD), price_vnum(0) {
		memset(&alSockets, 0, sizeof(alSockets));
		memset(&aAttr, 0, sizeof(aAttr));
	}
#endif

//Find
	SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX,
		
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM,
	SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP,
#endif