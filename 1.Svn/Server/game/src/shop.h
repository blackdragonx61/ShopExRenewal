//Find
			int		itemid;
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
			long	alSockets[ITEM_SOCKET_MAX_NUM];
			TPlayerItemAttribute	aAttr[ITEM_ATTRIBUTE_MAX_NUM];
			DWORD price_type;
			DWORD price_vnum;
#endif

//Find
				pkItem = NULL;
		
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
				price_type = SHOPEX_GOLD,
				price_vnum = 0,
				memset(&alSockets, 0, sizeof(alSockets));
				memset(&aAttr, 0, sizeof(aAttr));
#endif