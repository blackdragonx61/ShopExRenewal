//Find
			switch (shop_tab.coinType)
			{
			case SHOP_COIN_TYPE_GOLD:
				if (bOtherEmpire) // no empire price penalty for pc shop
					pack_tab.items[i].price = shop_tab.items[i].price * 3;
				else
					pack_tab.items[i].price = shop_tab.items[i].price;
				break;
			case SHOP_COIN_TYPE_SECONDARY_COIN:
				pack_tab.items[i].price = shop_tab.items[i].price;
				break;
			}
			memset(pack_tab.items[i].aAttr, 0, sizeof(pack_tab.items[i].aAttr));
			memset(pack_tab.items[i].alSockets, 0, sizeof(pack_tab.items[i].alSockets));
			
///Change
#if defined(ENABLE_RENEWAL_SHOPEX)
			pack_tab.items[i].price_type = shop_tab.items[i].price_type;
			pack_tab.items[i].price_vnum = shop_tab.items[i].price_vnum;
			pack_tab.items[i].price = shop_tab.items[i].price;
			if (bOtherEmpire && pack_tab.items[i].price_type == SHOPEX_GOLD)
				pack_tab.items[i].price *= 3;
			thecore_memcpy(pack_tab.items[i].aAttr, shop_tab.items[i].aAttr, sizeof(pack_tab.items[i].aAttr));
			thecore_memcpy(pack_tab.items[i].alSockets, shop_tab.items[i].alSockets, sizeof(pack_tab.items[i].alSockets));
#else
			switch (shop_tab.coinType)
			{
			case SHOP_COIN_TYPE_GOLD:
				if (bOtherEmpire) // no empire price penalty for pc shop
					pack_tab.items[i].price = shop_tab.items[i].price * 3;
				else
					pack_tab.items[i].price = shop_tab.items[i].price;
				break;
			case SHOP_COIN_TYPE_SECONDARY_COIN:
				pack_tab.items[i].price = shop_tab.items[i].price;
				break;
			}
			memset(pack_tab.items[i].aAttr, 0, sizeof(pack_tab.items[i].aAttr));
			memset(pack_tab.items[i].alSockets, 0, sizeof(pack_tab.items[i].alSockets));
#endif

//Find
	switch (shopTab.coinType)
	{
		case SHOP_COIN_TYPE_GOLD:
			if (it->second)
				dwPrice *= 3;

			if (ch->GetGold() < (int) dwPrice)
			{
				sys_log(1, "ShopEx::Buy : Not enough money : %s has %d, price %d", ch->GetName(), ch->GetGold(), dwPrice);
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
			}
			break;
		case SHOP_COIN_TYPE_SECONDARY_COIN:
			{
				int count = ch->CountSpecifyTypeItem(ITEM_SECONDARY_COIN);
				if (count < dwPrice)
				{
					sys_log(1, "ShopEx::Buy : Not enough myeongdojun : %s has %d, price %d", ch->GetName(), count, dwPrice);
					return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX;
				}
			}
			break;
	}
	
///Change
#if defined(ENABLE_RENEWAL_SHOPEX)
	switch (r_item.price_type)
	{
	case SHOPEX_GOLD:
		if (it->second)
			dwPrice *= 3;
		if (ch->GetGold() < static_cast<int>(dwPrice))
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
		break;
	case SHOPEX_SECONDARY:
		if (ch->CountSpecifyTypeItem(ITEM_SECONDARY_COIN) < static_cast<int>(dwPrice))
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX;
		break;
	case SHOPEX_ITEM:
		if (ch->CountSpecifyItem(r_item.price_vnum) < static_cast<int>(dwPrice))
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM;
		break;
	case SHOPEX_EXP:
		if (ch->GetExp() < dwPrice)
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP;
	}
#else
	switch (shopTab.coinType)
	{
	case SHOP_COIN_TYPE_GOLD:
		if (it->second)	// if other empire, price is triple
			dwPrice *= 3;

		if (ch->GetGold() < (int)dwPrice)
		{
			sys_log(1, "ShopEx::Buy : Not enough money : %s has %d, price %d", ch->GetName(), ch->GetGold(), static_cast<int>(dwPrice));
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
		}
		break;
	case SHOP_COIN_TYPE_SECONDARY_COIN:
	{
		int count = ch->CountSpecifyTypeItem(ITEM_SECONDARY_COIN);
		if (count < static_cast<int>(dwPrice))
		{
			sys_log(1, "ShopEx::Buy : Not enough myeongdojun : %s has %d, price %d", ch->GetName(), count, static_cast<int>(dwPrice));
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX;
		}
	}
	break;
	}
#endif

//Find
	switch (shopTab.coinType)
	{
		case SHOP_COIN_TYPE_GOLD:
			ch->PointChange(POINT_GOLD, -dwPrice, false);
			break;
		case SHOP_COIN_TYPE_SECONDARY_COIN:
			ch->RemoveSpecifyTypeItem(ITEM_SECONDARY_COIN, dwPrice);
			break;
	}
	
///Change
#if defined(ENABLE_RENEWAL_SHOPEX)
	switch (r_item.price_type)
	{
	case SHOPEX_GOLD:
		ch->PointChange(POINT_GOLD, -static_cast<int>(dwPrice), false);
		break;
	case SHOPEX_SECONDARY:
		ch->RemoveSpecifyTypeItem(ITEM_SECONDARY_COIN, dwPrice);
		break;
	case SHOPEX_ITEM:
		ch->RemoveSpecifyItem(r_item.price_vnum, dwPrice);
		break;
	case SHOPEX_EXP:
		ch->PointChange(POINT_EXP, -static_cast<int>(dwPrice), false);
	}
	{
		/*Attr*/
		item->SetAttributes(r_item.aAttr);

		/*Socket*/
		for (BYTE i = 0; i < ITEM_SOCKET_MAX_NUM; i++)
			if (r_item.alSockets[i] != 0)
				item->SetSocket(i, r_item.alSockets[i]);
	}
#else
	switch (shopTab.coinType)
	{
	case SHOP_COIN_TYPE_GOLD:
		ch->PointChange(POINT_GOLD, -dwPrice, false);
		break;
	case SHOP_COIN_TYPE_SECONDARY_COIN:
		ch->RemoveSpecifyTypeItem(ITEM_SECONDARY_COIN, dwPrice);
		break;
	}
#endif