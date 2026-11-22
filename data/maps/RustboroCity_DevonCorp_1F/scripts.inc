RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Chào mừng bạn đã đến\n"
	.string "với TẬP ĐOÀN DEVON.\p"
	.string "Chúng tôi tự hào là người đã sản xuất\n"
	.string "vật phẩm, dược phẩm để phục vụ đời sống.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Cái bạn nhân viên đó khờ quá, nên bị\n"
	.string "người ta lấy mất tiêu cái bưu kiện rồi.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Ê, cái đôi GIÀY CHẠY BỘ đó!\n"
	.string "Là một trong các sản phẩm của chúng tôi đó!\p"
	.string "Tui thực sự rất hãnh diện khi có\n"
	.string "người sử dụng sản phẩm mình làm ra.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Cái bưu kiện bị cướp…\p"
	.string "Tất nhiên là quan trọng rồi, nhưng\n"
	.string "mà không phải ai cũng xài được đâu.\p"
	.string "Theo suy đoán của tui, cái tên cướp\n"
	.string "đó đầu óc chắc không có sáng lắm đâu.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "Hình như cái bạn đó đã lấy lại\n"
	.string "được bưu kiện DEVON bị cướp rồi.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Xin lỗi, chỉ những người có\n"
	.string "thẩm quyền mới được vô đây.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "Sao mà khờ vậy trời.\n"
	.string "Sao để người ta cướp của mình vậy trời?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Chào em!\n"
	.string "Em lúc nào cũng được chào đón ở đây!$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Mẫu thử đá với kim loại được\n"
	.string "trưng bày trong hộp kiếng này.\p"
	.string "Trên kiếng có đề\n"
	.string "vài dòng chữ…\p"
	.string "“TẬP ĐOÀN DEVON khởi đầu từ một\n"
	.string "nhà sản xuất đá từ các mỏ đá.\p"
	.string "“Công ty cũng sản xuất sắt từ\n"
	.string "những mảnh sắt vụn ở trong cát.\p"
	.string "“Từ 1 nhà sản xuất kim loại thô\n"
	.string "mà DEVON mới được thành lập.\p"
	.string "“Hiện nay, DEVON là nhà sản xuất\n"
	.string "các sản phẩm công nghiệp đa dạng.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Nguyên mẫu và sản phẩm thử\n"
	.string "được trưng bày trong đây.\p"
	.string "Trên kiếng có đề vài dòng chữ…\p"
	.string "“Ngoài sản phẩm công nghiệp,\n"
	.string "DEVON còn làm mấy sản phẩm khác\l"
	.string "như là dược phẩm để phục vụ đời sống.\p"
	.string "“Gần đây, DEVON đã bắt đầu quảng bá\n"
	.string "các công cụ dành cho NHL, bao gồm\l"
	.string "QUẢ CẦU POKéMON và hệ thống BẢN ĐỒ.”$"

