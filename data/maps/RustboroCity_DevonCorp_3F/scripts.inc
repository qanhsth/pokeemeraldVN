RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_CORP_3F_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_CORP_3F_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_CORP_3F_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement LOCALID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Chú là ÔNG THẠCH,\n"
	.string "CHỦ TỊCH TẬP ĐOÀN DEVON.\p"
	.string "Chú có nghe người ta nói về con!\p"
	.string "Con đã cứu nhân viên của chú,\n"
	.string "không chỉ một mà tới hai lần lận!\p"
	.string "Chú có cài này muốn nhờ\n"
	.string "một người tuyệt vời như con.\p"
	.string "Chú biết là con đang giao kiện hàng\n"
	.string "tới XƯỞNG ĐÓNG TÀU ở TP.CẢNG.\p"
	.string "Trên đường đi, phiền con ghé\n"
	.string "qua THÔN ĐẢO xíu được không?\p"
	.string "Chú muốn con gới LÁ THƠ\n"
	.string "cho ĐẠI ở THÔN ĐẢO.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "ÔNG THẠCH: Giờ con biết\n"
	.string "chú là CHỦ TỊCH rồi.\p"
	.string "Chú cũng không có tới mức\n"
	.string "nhờ người ta mà không trả ơn.\p"
	.string "Cho nên là chú muốn con cầm lấy cái này!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} nhận BẢN ĐỒ.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "ÔNG THẠCH: Cái đó…\p"
	.string "Là thiết bị ĐỊNH VỊ,\n"
	.string "hay nói BẢN ĐỒ cho dễ hiểu.\p"
	.string "Đây là thiết bị bắt\n"
	.string "buộc phải có cho NHL.\p"
	.string "Trong đây có bản đồ vùng HOENN.\p"
	.string "Con có thể dễ dàng coi\n"
	.string "chỗ THÔN ĐẢO với TP.CẢNG!\p"
	.string "À mà chú có nghe nói nhóm tội phạm\n"
	.string "bị truy nã--MAGMA với AQUA, hình như--\l"
	.string "tụi nó đang làm cái gì đó rất mờ ám.\p"
	.string "Chú nghĩ là con nên nghỉ ngơi\n"
	.string "xíu trước khi lên đường.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "ÔNG THẠCH: Vậy thì, {PLAYER},\n"
	.string "cẩn trọng nha!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "ÔNG THẠCH: Trông cậy vào con nha!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "ÔNG THẠCH: Đưa LÁ THƠ giùm chú rồi hả?\n"
	.string "Cảm ơn con nhiều!\p"
	.string "Đây là cách mà chú cảm ơn.\n"
	.string "Chắc chắn sẽ hữu ích với NHL như con.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "ÔNG THẠCH: POKéMON mà cầm cái CHIA\n"
	.string "KINH NGHIỆM thì nó sẽ nhận được\l"
	.string "một xíu KINH NGHIỆM trong trận đấu.\p"
	.string "Kể cả khi không chiến đấu đi nữa,\n"
	.string "thì nó vẫn sẽ nhận được KINH NGHIỆM.\p"
	.string "Có thể nói CHIA KINH NGHIỆM rất có\n"
	.string "ích để luyện cấp cho POKéMON yếu.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "ÔNG THẠCH: Hồi còn trẻ, chú\n"
	.string "chỉ có cắm đầu làm việc thôi.\p"
	.string "Nên là chú không có rành về\n"
	.string "mấy cái xu hướng hiện nay.\p"
	.string "Nhưng mà mấy đứa trẻ trẻ ai cũng muốn là\n"
	.string "NHL trong LIÊN ĐOÀN POKéMON phải không?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Ở đây là tầng thứ ba trong\n"
	.string "văn phòng của TẬP ĐOÀN DEVON.\p"
	.string "Phòng của CHỦ TỊCH\n"
	.string "cũng ở trên tầng này.\p"
	.string "À mà, tui rất là cảm kích vì\n"
	.string "những chuyện mà bạn đã làm.\p"
	.string "À… với lại, cái bưu kiện\n"
	.string "mà bạn lấy lại giùm tụi tui á…\p"
	.string "Nhờ bạn đưa qua chỗ XƯỞNG ĐÓNG\n"
	.string "TÀU ở TP.CẢNG được không?\p"
	.string "Tại vì là tui sợ tụi nó\n"
	.string "đi qua trộm nữa mắc công.\p"
	.string "Ừ… Hehehe, vậy rồi, nhờ bạn\n"
	.string "làm giùm tui được không?\p"
	.string "A, phải rồi.\n"
	.string "Đứng đây chờ tui xíu nha!$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "CHỦ TỊCH có vài\n"
	.string "lời muốn nói.\p"
	.string "Xin hãy đi theo tui.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Xin hãy bước lên.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Nếu bạn tính qua XƯỞNG ĐÓNG TÀU, thì\n"
	.string "bạn cũng nên gặp THUYỀN TRƯỞNG SANG đi.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Sản phẩm mới của DEVON, CẦU TRÙNG\n"
	.string "với CẦU THỜI, đang rất phổ\l"
	.string "biến cho các NHL.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "Đây là bộ sưu tập các\n"
	.string "loại đá quý của CHỦ TỊCH.$"

