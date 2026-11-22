SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
#ifdef BUGFIX
	releaseall  @ Only gets called from EventScript_PokeBlockFeeder which uses lockall.
#endif
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Dạ, quý khách có muốn thoát\n"
	.string "KHU SĂN BẮT?$"

SafariZone_Text_TimesUp:
	.string "Đính đoang! Hết giờ!\n"
	.string "Trò chơi SĂN BẮT kết thúc.$"

SafariZone_Text_OutOfBalls:
	.string "Bạn đã hết CẦU SAFARI.\n"
	.string "Trò chơi SĂN BẮT kết thúc.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Would you like to place a {POKEBLOCK}\n"
	.string "on the {POKEBLOCK} FEEDER?$"

SafariZone_Text_PokeblockStillHere:
	.string "The {STR_VAR_1} you left\n"
	.string "before is still here.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "The {STR_VAR_1} was placed\n"
	.string "on the {POKEBLOCK} FEEDER.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Chào mừng đến với KHU SĂN BẮT!\p"
	.string "Ở đây, bạn sẽ gặp được nhiều loại\n"
	.string "POKéMON hiếm thấy ở HOENN,\p"
	.string "trong trạng thái hoang dã, chưa được\n"
    .string "thuần hóa tại môi trường tự nhiên.\p"
    .string "Hơn nữa, chúng tôi đã hoan nghênh,\n"
    .string "chào đón các NHL POKéMON.\p"
    .string "Chúng tôi mong là bạn sẽ bắt\n"
	.string "được POKéMON mà mình cần!\p"
    .string "KHU SĂN BẮT cảm ơn quý khách!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Chào mừng đến với KHU SĂN BẮT!\n"
	.string "Phải chăng đây là lần đầu của quý khách?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
    .string "KHU SĂN BẮT cảm ơn quý khách!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Bước vô KHU SĂN BẮT, quý khách\n"
	.string "sẽ được tặng 30 CẦU SAFARI để\l"
	.string "bắt POKéMON.\p"
	.string "Trò chơi SĂN BẮT sẽ kết thúc khi\n"
	.string "hết CẦU SAFARI, hoặc là quý khách\l"
	.string "đã đi được 500 bước.\p"
    .string "KHU SĂN BẮT cảm ơn quý khách!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Chào mừng đến với KHU SĂN BẮT!\p"
	.string "Bắt được hết POKéMON chỉ với ¥500!\n"
	.string "Quý khách có muốn vô không?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "Dạ rồi.\n"
	.string "Mong quý khách ghé lại!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Quý khách không đủ tiền.\n"
	.string "Xin thứ lỗi.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Dạ, phí là ¥500.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Dạ, CẦU SAFARI của quý khách đây.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} nhận 30 CẦU SAFARI.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Chúng tôi sẽ thông báo khi\n"
	.string "kết thúc game.\p"
	.string "Nên là quý khách cứ thoải mái!\n"
	.string "Mà tận hưởng chuyến săn bắt!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Xin thứ lỗi!\n"
	.string "BOX trong MÁY quý khách đã đầy.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Quý khách ơi!\n"
	.string "Quý khách chưa có HỘP {POKEBLOCK}.\p"
	.string "Sẽ dễ chơi hơn nếu\n"
    .string "quý khách sử dụng {POKEBLOCK}.\p"
    .string "Xin hãy quay lại với HỘP {POKEBLOCK}.\p"
	.string "Quý khách có thể nhận HỘP {POKEBLOCK}\n"
    .string "ở HỘI THI ĐẤU TP.BIỂN.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Vẫn còn thời gian. Quý khách\n"
	.string "có muốn thoát KHU SĂN BẮT không?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Xin hãy tận hưởng chuyến\n"
	.string "săn bắt!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Dạ rồi.\p"
	.string "Tôi sẽ thu lại CẦU SAFARI\n"
	.string "còn dư của quý khách.\p"
	.string "Cảm ơn quý khách đã ghé qua chơi.\n"
	.string "Mong được gặp lại quý khách.$"

SafariZone_South_Text_GoodLuck:
	.string "Chúc may mắn!\p"
	.string "Nếu cần gì thêm, xin đừng\n"
	.string "ngại, hãy nói cho tôi biết!$"

SafariZone_South_Text_Boy:
	.string "Bạn có biêt?\p"
	.string "Nếu để {POKEBLOCK} trong hộp vuông,\n"
	.string "POKéMON sẽ bu lại.$"

SafariZone_South_Text_Man:
	.string "Tui muốn đi lên nữa, mà\n"
	.string "quên đem XE ĐẠP mất tiêu.\p"
	.string "Linh cảm nói cho tui biết là có\n"
	.string "POKéMON hiếm ở ngoại ô.$"

SafariZone_Southwest_Text_Woman:
	.string "Lâu lâu tui chọi 1 cái {POKEBLOCK}\n"
	.string "vô POKéMON, thì nó ngó lơ đi.\p"
	.string "POKéMON có thích hay ghét\n"
	.string "món ăn nào không?$"

SafariZone_Northwest_Text_Man:
	.string "Phì… phì…\n"
	.string "Cuối cùng…cũng tới được đây…mà…\p"
	.string "Đuối quá… không còn\n"
	.string "sức để bắt POKéMON nữa…$"

SafariZone_North_Text_Fisherman:
	.string "Tui đang thực hiện nhiệm vụ đi kiếm\n"
	.string "POKéMON hệ NƯỚC, không thấy được ở HOENN.\p"
	.string "Bạn có biết cái hồ nằm ở đâu không?$"

SafariZone_North_Text_Man:
	.string "Tui sẽ bắt thiệt nhiều POKéMON hiếm\n"
	.string "rồi đem đi đổi với mấy đứa bạn!$"

SafariZone_South_Text_Youngster:
	.string "Tui để 1 cái {POKEBLOCK} vô {POKEBLOCK} FEEDER.\n"
	.string "Rồi không hiểu sao mất tiêu luôn.\p"
	.string "Chắc bị con POKéMON nào\n"
	.string "ăn mất mà không để ý.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "Mẹo cho NHL ở KHU SĂN BẮT!\p"
	.string "Chọi {POKEBLOCK} vô POKéMON để\n"
	.string "giữ chưn tụi nó lại.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "“Nghỉ mệt một xíu đi.”\n"
	.string "NHÀ NGHỈ NGƠI$"

SafariZone_RestHouse_Text_Youngster:
	.string "Tui không có {POKEBLOCK}, mà cũng\n"
	.string "bắt được kha khá POKéMON nè.\p"
	.string "Bạn có thể tăng cơ hội bắt được bằng\n"
	.string "cách bước lại gần POKéMON trước khi\l"
	.string "chọi CẦU SAFARI.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Nếu mà xài {POKEBLOCK}, POKéMON sẽ\n"
	.string "không chạy liền.\p"
	.string "Tức là dù có chọi {POKEBLOCK}S vô\n"
	.string "POKéMON, thì cũng không có tác dụng lắm.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Nếu bạn để {POKEBLOCK} vô FEEDER,\n"
	.string "POKéMON sẽ bị thu hút.\p"
	.string "Tui nghĩ POKéMON có cùng tánh cách\n"
	.string "sẽ bị kéo lại bởi {POKEBLOCK} phù hợp.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Khu này đang được thi công.\n"
	.string "Không đi qua được, xin lỗi!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Dự án mở rộng KHU SĂN BẮT\n"
	.string "đã hoàn thành.\p"
	.string "Hy vọng bạn thích khu mới này.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Khu này đang được thi công.\n"
	.string "Không đi qua được, xin lỗi!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Trời! Ơi! Đó giờ chưa thấy\n"
	.string "mấy con POKéMON này luôn á!$"

SafariZone_Southeast_Text_FatMan:
	.string "POKéMON ở khu này\n"
	.string "hoàn toàn mới với tui.\p"
	.string "Và tui được phép bắt mấy con\n"
	.string "POKéMON này luôn! Quá đã!$"

SafariZone_Southeast_Text_RichBoy:
	.string "POKéMON ở đây hình như tới từ\n"
	.string "nơi khác HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Tui còn có mấy cái CẦU SAFARI à.\p"
	.string "Giờ đang lăn tăn, không biết\n"
	.string "nên bắt con nào nữa.$"

SafariZone_Northeast_Text_Woman:
	.string "Nghe nói là ở đây có PIKACHU.\n"
	.string "Mà ở chỗ nào mới được?$"

SafariZone_Northeast_Text_Girl:
	.string "Chời ơi!\n"
	.string "Tui hong có bắt được gì luôn!\p"
	.string "Chắc phải bỏ phí tiền, tại\n"
	.string "có bắt được con nào đâu!$"
