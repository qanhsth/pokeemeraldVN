@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Con POKéMON này đã từng thắng\n"
	.string "CUỘC THI SẮC ĐẸP.\p"
	.string "Nhưng giờ thì sao? Bữa nay, nó\n"
	.string "đã thắng CUỘC THI TRÍ KHÔN!\p"
	.string "Khiếp sợ khả năng của chính mình quá…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Tui tham gia nhiều CUỘC THI rồi,\n"
	.string "nên là tui mới biết cách để thắng.\p"
	.string "Nếu bạn tham gia CUỘC THI NGẦU,\n"
	.string "chiêu nào ngầu sẽ được cộng điểm.\p"
	.string "Nhưng mà chiêu nào dễ thương hoặc\n"
	.string "thông minh thì sẽ không ổn đâu.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Cái anh trai đó, đem một đống\n"
	.string "{POKEBLOCK} mới thắng được.\p"
	.string "Nếu mà đem nhiều như vậy, thì\n"
	.string "mình có thắng được như ảnh không ta?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Trời, chỗ này rộng quá đi thôi!\p"
    .string "Không khí căng thẳng quá… không\n"
    .string "giống như hội trường THI ở quê.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC: Rồi, POKéMON THÔNG MINH và\n"
	.string "CHỦ của nó, đã sẵn sàng chưa?!\p"
	.string "Hãy biểu diễn thật đẹp mắt!\n"
	.string "Bắt đầu thôi!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "GIÁM KHẢO: Bạn có thích CUỘC THI này?\p"
	.string "Kéo thêm 3 người nữa quay lại đi,\n"
	.string "rồi mấy bạn sẽ được tham gia THI!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ayayayay…\n"
	.string "Tui vô lộn CUỘC THI rồi.\p"
	.string "Tui cho POKéMON cơ bắp vô\n"
	.string "CUỘC THI TRÍ KHÔN…\p"
	.string "Ráng lên, làm họ ngạc nhiên\n"
	.string "với cú ĐẬP ĐÁ thông minh đi.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Ta đã dành biết bao năm, để lại\n"
    .string "tâm trí của mình, quyết nuôi dạy\l"
    .string "con POKéMON này thông minh hơn.\p"
    .string "Nó sẽ không dễ dàng bị đánh bại bởi\n"
    .string "POKéMON của một đứa nhóc nào đó.\p"
	.string "Vợ yêu của ta, nàng có nhìn thấy không?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Đây rồi!\p"
	.string "Nếu POKéMON của tui ra đòn khôn xíu,\n"
	.string "khán giả sẽ ồ lên cho mà coi!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Ôi trời ơi!\p"
	.string "Đòn HÚT MÁU của bé yêu ZUBAT quá ư là dễ\n"
	.string "thương, nên tui cứ xài đi xài lại hoài!\p"
	.string "Nhưng mà mấy con người ác độc này\n"
	.string "không có chịu thừa nhận gì hết!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah! Ông ngoại đẹp quá!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Cho dù NHL có xài cùng một loại\n"
	.string "POKéMON đi nữa, họ đều sử dụng\l"
	.string "chiêu thức khác nhau để trình diễn.\p"
	.string "Giống như cách mà con người ta\n"
	.string "có nhiều phong cách chiến đấu vậy.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Tui POKéMON nhìn còn\n"
	.string "khôn hơn CHỦ của nó. Rất nhiều.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Dù sao đi nữa, tui vẫn thích\n"
    .string "CUỘC THI TRÍ KHÔN.\p"
    .string "Màu xanh của trí khôn…\n"
    .string "Nó thiệt… thiệt… ngầu.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC: Bạn cũng tham gia CUỘC THI\n"
	.string "SẮC ĐẸP sao? Chúc may mắn!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "GIÁM KHẢO: Ah, mỗi con POKéMON\n"
	.string "là hình mẫu sắc đẹp lý tưởng!\p"
	.string "Trời, làm quên chấm điểm luôn rồi!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "POKéMON đẹp cỡ này…\n"
	.string "Sẽ không có con nào đẹp hơn đâu.\p"
	.string "Đôi mắt của mọi người chỉ\n"
	.string "hướng về sắc đẹp của tụi tui mà thôi.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah!\p"
	.string "Tui có chải lông và chăm sóc POKéMON\n"
    .string "cẩn thận để chuẩn bị cho CUỘC THI…\p"
    .string "Nhưng mà tui lỡ làm quá rồi…\n"
    .string "Bộ lông của nó bị xù lên rồi…\p"
	.string "Giờ sao?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "TIA CỰC QUANG này chói quá,\n"
    .string "giám khảo sẽ không nhìn được đâu.\p"
    .string "Ủa mà, khoan…\n"
    .string "Vậy rồi cũng có được gì đâu!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Con POKéMON xinh đẹp này\n"
	.string "cứ như là tui hồi còn trẻ vậy.\p"
	.string "Vừa nói xong, ông chồng tui\n"
	.string "phun cà phê cái phèo.\p"
	.string "Ủa là mắc cười lắm hả?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Nếu tui mà thắng CUỘC THI\n"
	.string "SẮC ĐẸP, thì chắc chắn là\l"
	.string "tui sẽ vui. Hơn mọi khi luôn á chứ.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Bạn có muốn ngắm nhìn tất cả những\n"
    .string "POKéMON xinh xắn này không!\l"
    .string "Mình thực sự thích sự lộng lẫy như vầy!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Bạn không chỉ có dựa vào\n"
	.string "sắc đẹp mà thắng được đâu.\p"
	.string "Bạn phải chăm chút cho POKéMON\n"
	.string "để nó sáng bóng như của tui vậy nè.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC: Ụa ụa! Gì dạ!\n"
	.string "Đang THI mà!\p"
	.string "Ra ngoài chỗ đăng ký\n"
	.string "giùm cái được không?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "GIÁM KHẢO: Màn trình diễn\n"
	.string "dễ thương và lôi cuốn làm sao!\p"
	.string "Ôi trời ơi! Đòn TƯỚI SÂN\n"
	.string "đẹp mỹ mãn!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Rồi luôn… Bé AZURILL bị\n"
	.string "POKéMON làm mờ nhạt rồi.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "POKéMON của tui chưa bao giờ thắng trận,\n"
	.string "mà nếu để vô CUỘC THI thì lại khác!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "POKéMON của tui có Điệu MÚA CÁNH HOA\n"
	.string "thật là trang nhã.\p"
	.string "Tui sẽ không để ai phá hoại\n"
	.string "màn trình diễn của nó đâu.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "POKéMON cũng dễ thương hết.\p"
	.string "Nếu mà, POKéMON được cho đi\n"
	.string "trình diễn sự dễ thương…\p"
	.string "Chắc chắn là nó sẽ còn dễ thương\n"
	.string "hơn mấy con khác gấp vạn lần.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Con tui đang THI ở trong này.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Cố lên, con. Cố lên!\n"
	.string "POKéMON của con là nhất!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Tui thấy con bé ở đằng kia\n"
	.string "là dễ thương nhất.\p"
	.string "Ủa sao vậy? Người ta chỉ đánh\n"
	.string "giá vẻ đẹp của POKéMON thôi hả?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Trời, nhìn mấy con POKéMON này,\n"
	.string "làm tui muốn bắt về nuôi quá!\p"
	.string "Chắc tui phải đi bắt mấy con mới được!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "SÀN THI SẮC ĐẸP\n"
	.string "ĐỂ POKéMON QUYẾN RŨ BẠN!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "SÀN THI DỄ THƯƠNG\n"
	.string "ĐỂ POKéMON MÊ HOẶC BẠN!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "SÀN THI TRÍ KHÔN\n"
	.string "ĐỂ POKéMON LÀM BẠN NGẠC NHIÊN!$"

