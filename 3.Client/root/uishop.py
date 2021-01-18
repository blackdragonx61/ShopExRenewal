#Find
				self.middleRadioButtonGroup.OnClick(1)
			
#Change
				#Fix for tabs
				self.smallRadioButtonGroup.OnClick(0)
#Find
	def OverInItem(self, slotIndex):
	
#Change func
	def OverInItem(self, slotIndex):
		slotIndex = self.__GetRealIndex(slotIndex)
		if mouseModule.mouseController.isAttached():
			return

		if self.tooltipItem:
			if app.ENABLE_RENEWAL_SHOPEX:
				PriceType = shop.GetItemPriceType(slotIndex)
				if PriceType == shop.SHOPEX_GOLD:
					self.tooltipItem.SetShopItem(slotIndex)
				elif PriceType == shop.SHOPEX_SECONDCOIN:
					self.tooltipItem.SetShopItemBySecondaryCoin(slotIndex)
				else:
					self.tooltipItem.SetShopItemByShopEx(slotIndex, PriceType)
			else:
				if shop.SHOP_COIN_TYPE_GOLD == shop.GetTabCoinType(self.tabIdx):
					self.tooltipItem.SetShopItem(slotIndex)
				else: 
					self.tooltipItem.SetShopItemBySecondaryCoin(slotIndex)