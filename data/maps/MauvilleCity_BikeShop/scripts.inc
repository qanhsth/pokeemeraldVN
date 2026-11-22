MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	message MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne
	waitmessage
	multichoice 21, 8, MULTI_BIKE, TRUE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	case 1, MauvilleCity_BikeShop_EventScript_GetAcroBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseMachBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	special SwapRegisteredBike
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Trời, trời, gì đây?\n"
	.string "Vị khách đầy nhiệt huyết!\p"
	.string "Tui hả? Bạn có thể kêu tui là QUANG.\n"
	.string "Tui là chủ tiệm bán xe đạp.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "QUANG: GIÀY CHẠY BỘ của bạn…\n"
	.string "Sao nhìn dơ hèm vậy nè.\p"
	.string "Bạn từ phương xa tới đây hả?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "QUANG: Vậy hả?\p"
	.string "Vậy chắc là bạn không\n"
	.string "cần XE ĐẠP của tui rồi.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "QUANG: Hm, hm… … … … …\p"
	.string "Bạn nói là bạn đi từ MỸ BẠCH\n"
	.string "tới đây luôn?\p"
	.string "Trời đất ơi!\n"
	.string "Xa dữ vậy má!\p"
	.string "Nếu mà bạn mua XE ĐẠP bên tui, bạn\n"
	.string "có thể đi bất kỳ đâu, và còn cảm nhận\l"
	.string "được hơi gió thoảng khi đi nữa!\p"
	.string "Tui nói cho bạn nghe!\n"
	.string "Tui sẽ cho bạn 1 chiếc XE ĐẠP!\p"
	.string "Ủa mà khoan cái!\p"
	.string "Tui quên là có tới\n"
	.string "2 loại XE ĐẠP lận!\p"
	.string "Có loại XE ĐẠP XỊN với\n"
	.string "XE ĐẠP THỂ THAO!\p"
	.string "XE ĐẠP XỊN dành cho người\n"
	.string "muốn cảm nhận hơi gió khi chạy!\p"
	.string "Còn XE ĐẠP THỂ THAO dành cho\n"
	.string "người có tuyệt kỹ chạy xe!\p"
	.string "Tui rất là rộng lượng, nên bạn\n"
	.string "có thể lựa cái nào mình thích!\p"
	.string "Bạn muốn lấy cái nào?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} chọn XE ĐẠP XỊN.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} chọn XE ĐẠP THỂ THAO.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "QUANG: Nếu bạn có ý định đổi\n"
    .string "XE ĐẠP, thì cứ ghé qua nha!$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "QUANG: Ủa? Bạn muốn\n"
	.string "đổi XE ĐẠP hả?$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "QUANG: Không thành vấn đề!\n"
	.string "Tui sẽ đổi lại XE ĐẠP cho bạn!$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} đổi XE ĐẠP XỊN\n"
	.string "lấy XE ĐẠP THỂ THAO.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} đổi XE ĐẠP THỂ THAO\n"
	.string "lấy XE ĐẠP XỊN.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "QUANG: Chạy đã lắm phải ôn!\n"
	.string "Bạn thấy thích là được!$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Ủa? Cái XE ĐẠP tui đưa, bạn\n"
	.string "để đâu rồi?\p"
	.string "À, để trong MÁY TÍNH.\p"
	.string "Vậy đi lấy ra đi,\n"
	.string "rồi lại đây đổi với tui!\p"
	.string "Mong bạn sẽ luôn\n"
	.string "thượng lộ bình an!$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "Tui vừa làm vừa học\n"
	.string "về XE ĐẠP.\p"
	.string "Nếu bạn muốn biết cách chạy XE ĐẠP,\n"
	.string "có mấy cuốn sách ở đằng sau\l"
	.string "có chỉ cách chạy đó.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "Đây là sách chỉ cách chạy XE ĐẠP XỊN.\p"
	.string "Bạn muốn đọc trang nào?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "XE ĐẠP di chuyển theo hướng mũi tên\n"
	.string "lên - xuống - qua - lại.\p"
	.string "Nó sẽ dần tăng tốc khi đạp bánh.\p"
	.string "Chi cần buông nút là ngừng được.\n"
	.string "XE ĐẠP sẽ chậm lại rồi ngừng.\p"
	.string "Đọc trang khác không?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "XE ĐẠP XỊN có tốc độ cao, nhưng mà\n"
	.string "không có thắng liền được.\p"
	.string "Sẽ hơi khó chạy khi mà\n"
	.string "đi vô góc chật.\p"
	.string "Buông Tay Cầm một xíu trước khi vô\n"
	.string "góc để đi chậm, dễ điều khiển hơn.\p"
	.string "Đọc trang khác không?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Có mấy cái đồi cát ở\n"
	.string "vùng HOENN.\p"
	.string "Cát nó dễ lúng làm cho\n"
	.string "mình khó di chuyển hơn.\p"
	.string "Mà nếu bạn có XE ĐẠP XỊN, bạn\n"
	.string "có thể lướt nhanh qua được.\p"
	.string "Đọc trang khác không?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "Đây là sách về XE ĐẠP THỂ THAO.\p"
	.string "Bạn muốn đọc trang nào?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Nhấn Nút B khi đang chạy,\n"
	.string "để nâng bánh trước lên.\p"
	.string "Bạn có thể nhảy xe bằng bánh trước\n"
	.string "sử dụng Nút Tay Cầm.\p"
	.string "Kỹ thuật này được gọi là nhấc bánh.\p"
	.string "Đọc trang khác không?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "Đè Nút B để\n"
	.string "nhảy XE ĐẠP tại chỗ.\p"
	.string "Kỹ thuật này được gọi là nhảy thỏ.\p"
	.string "Bạn có thể vừa chạy vừa nhảy luôn.\p"
	.string "Đọc trang khác không?$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Nhấn Nút B cùng lúc với Nút\n"
	.string "Tay Cầm để nhảy.\p"
	.string "Nhấn Nút qua - lại\n"
	.string "để nhảy ngang hông.\p"
	.string "Nhấn nút lui để đổi hướng\n"
	.string "XE ĐẠP khi đang chạy.\p"
	.string "Đọc trang khác không?$"

