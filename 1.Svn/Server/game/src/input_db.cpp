//Find
	/*
	 * SHOP
	 */

	if (decode_2bytes(data) != sizeof(TShopTable))
	{
		sys_err("shop table size error");
		thecore_shutdown();
		return;
	}
	data += 2;

	size = decode_2bytes(data);
	data += 2;
	sys_log(0, "BOOT: SHOP: %d", size);


	if (size)
	{
		if (!CShopManager::instance().Initialize((TShopTable *) data, size))
		{
			sys_err("shop table Initialize error");
			thecore_shutdown();
			return;
		}
		data += size * sizeof(TShopTable);
	}
	
///Add
#if defined(ENABLE_RENEWAL_SHOPEX)
	/*
	 * SHOPEX
	 */

	if (decode_2bytes(data) != sizeof(TShopTable))
	{
		sys_err("shopex table size error");
		thecore_shutdown();
		return;
	}
	data += 2;

	size = decode_2bytes(data);
	data += 2;
	sys_log(0, "BOOT: SHOPEX: %d", size);


	if (size)
	{
		if (!CShopManager::instance().InitializeShopEX((TShopTable*)data, size))
		{
			sys_err("shopex table Initialize error");
			thecore_shutdown();
			return;
		}
		data += size * sizeof(TShopTable);
	}
#endif