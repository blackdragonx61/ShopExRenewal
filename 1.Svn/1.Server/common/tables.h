//Find in : SShopItemTable
	BYTE		display_pos;
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	long	alSockets[ITEM_SOCKET_MAX_NUM];
	TPlayerItemAttribute	aAttr[ITEM_ATTRIBUTE_MAX_NUM];
	DWORD 	price_type;
	DWORD 	price_vnum;
	SShopItemTable() : price_type(1), price_vnum(0) {
		memset(&alSockets, 0, sizeof(alSockets));
		memset(&aAttr, 0, sizeof(aAttr));
	}
#endif