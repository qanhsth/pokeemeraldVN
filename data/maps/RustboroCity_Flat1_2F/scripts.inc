RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Ngày nào cũng cực hết trơn…\p"
	.string "Sao cực hả?\n"
	.string "Còn phải hỏi?\p"
	.string "Không biết nên làm\n"
	.string "món gì để ăn đó.\p"
	.string "Ngày nào cũng suy nghĩ\n"
	.string "món ăn không phải dễ đâu.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Chào con!\n"
	.string "Chào mừng đến với gia đình MUỐI TIÊU.\p"
	.string "Chú có 1 câu hỏi cho con.\n"
	.string "Nào giờ con có chăm con chưa?\p"
	.string "Con thấy đó, chú mới làm cha thôi, nên\n"
	.string "là chuyện nuôi con vẫn còn mới với chú.\p"
	.string "Giờ đang có 1 vấn đề. Con gái\n"
	.string "chú, AN, nó không chịu cười.\p"
	.string "Chú nghĩ là nó sẽ mỉm cười\n"
	.string "nếu chú nói cái gì đó vui vui.\p"
	.string "Con có biết từ nào vui vui\n"
	.string "chỉ chú với được không?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Chú có nói “{STR_VAR_1}”\n"
	.string "để chọc cười rồi.\p"
	.string "Con có biết từ nào\n"
	.string "hay hơn không?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Tuyệt vời.\n"
	.string "Vậy để chú nghe thử gợi ý của con nha.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "À, từ này đúng không?\p"
	.string "Chú sẽ ngồi đây chờ\n"
	.string "khi con có gợi ý mới.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "À, vậy hả.\n"
	.string "Vậy để thử coi sao?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "À ha! Cười rồi!\n"
	.string "Nhìn bé nó cười làm chú cũng vui lây!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "À, vậy hả.\n"
	.string "Vậy để thử coi được không?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hừmm… Bé nó không cười rồi.\n"
	.string "Chắc AN thuộc dạng nghiêm túc hay sao…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Vậy là con không biết từ nào hay hả?\n"
	.string "Vậy thôi để chú tự nghĩ.\p"
	.string "Hừmm…\n"
	.string "“{STR_VAR_1}” được không?\l"
	.string "Đâu để thử coi.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hừmm… Bé nó không cười rồi.\n"
	.string "Chắc AN thuộc dạng nghiêm túc hay sao…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "À, con không biết từ nào hay hết.\n"
	.string "Để chú thử chọc cười bằng cái\l"
	.string "từ mà chú nói hồi trước.\p"
	.string "À mà, nếu con nghĩ ra từ nào hay\n"
	.string "nhớ nói cho chú biết với nha!$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Cảm ơn con!\p"
	.string "Nhờ có con mà bé AN\n"
	.string "nó mới cười tươi như vậy!\p"
	.string "Thực ra nhìn chú vậy thôi\n"
	.string "chứ chú là thành viên chủ chốt\l"
	.string "trong TẬP ĐOÀN DEVON.\p"
	.string "Con có muốn chú tặng\n"
	.string "lại con cái gì không?\p"
	.string "A, biết rồi, chú sẽ thêm hình\n"
	.string "nền có hoạ tiết vô BOXES\l"
	.string "trong MÁY TÍNH cho con.\p"
	.string "Trong menu hình nền,\n"
	.string "chọn “BẠN BÈ.”\p"
	.string "Thì con sẽ có hình\n"
	.string "nền mà chú mới cho con.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "Thú nhồi bông POKéMON nè!$"
