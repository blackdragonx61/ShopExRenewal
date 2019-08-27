//Find
			memset(pack_tab.items[i].aAttr, 0, sizeof(pack_tab.items[i].aAttr));
			memset(pack_tab.items[i].alSockets, 0, sizeof(pack_tab.items[i].alSockets));
			
///Change
#ifdef ENABLE_RENEWAL_SHOPEX
			pack_tab.items[i].price_type = shop_tab.items[i].price_type;
			pack_tab.items[i].price_vnum = shop_tab.items[i].price_vnum;
			thecore_memcpy(pack_tab.items[i].aAttr, shop_tab.items[i].aAttr, sizeof(pack_tab.items[i].aAttr));
			thecore_memcpy(pack_tab.items[i].alSockets, shop_tab.items[i].alSockets, sizeof(pack_tab.items[i].alSockets));
#else
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
#ifndef ENABLE_RENEWAL_SHOPEX	
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
#else
	switch (r_item.price_type)
	{
		case 1:
			if (it->second)
				dwPrice *= 3;
			if (ch->GetGold() < static_cast<int>(dwPrice))
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
			break;
		case 2:
			{
				int count = ch->CountSpecifyTypeItem(ITEM_SECONDARY_COIN);
				if (count < dwPrice)
					return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY_EX;
			}
			break;
		case 3:
			{
				int count = ch->CountSpecifyItem(r_item.price_vnum);
				if (count < dwPrice)
					return SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM;
			}
			break;
		case 4:
			{
				int count = ch->GetExp();
				if (count < dwPrice)
					return SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP;
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
	
///Add
#ifdef ENABLE_RENEWAL_SHOPEX
	switch (r_item.price_type)
	{
		case 1: // gold
			ch->PointChange(POINT_GOLD, -dwPrice, false);
			break;
		case 2: // secondcoin
			ch->RemoveSpecifyTypeItem(ITEM_SECONDARY_COIN, dwPrice);
			break;
		case 3: // item
			ch->RemoveSpecifyItem(r_item.price_vnum, dwPrice);
			break;
		case 4: // exp
			ch->PointChange(POINT_EXP, -dwPrice, false);
			break;
	}
	item->SetAttributes(r_item.aAttr);
	item->SetSockets(r_item.alSockets);
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