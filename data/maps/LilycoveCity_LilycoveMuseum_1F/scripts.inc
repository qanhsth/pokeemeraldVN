LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_MUSEUM_1F_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum:
	.string "Chào mừng đến với BẢO TÀNG TP.BIỂN.\p"
	.string "Xin hãy thoải mái thưởng thức\n"
	.string "bộ sưu tập các tác phẩm nghệ\l"
	.string "thuật độc đáo về POKéMON.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings:
	.string "Ta là QUẢN ĐỐC của BẢO TÀNG\n"
	.string "nghệ thuật độc đáo này.\p"
	.string "Cảm giác rất vui khi thấy\n"
	.string "người trẻ như con tới đây.\p"
	.string "Con đã xem qua bộ sưu tập\n"
	.string "tranh vẽ chưa?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime:
	.string "À, vậy thôi không cản trở con nữa.\n"
	.string "Con cứ coi thoải mái đi.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings:
	.string "Ủa? Hình như con là\n"
	.string "NHL POKéMON thì phải.\p"
	.string "Con có hứng thú với\n"
	.string "tranh vẽ không?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat:
	.string "À vậy ha…\p"
	.string "Dù vậy, ta cũng thật hãnh diện\n"
	.string "khi con đã ghé qua.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe:
	.string "A, tuyệt vời!\n"
	.string "Con có thích tranh vẽ!\p"
	.string "Vậy, con có thể đi với ta xíu không?$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting:
	.string "Đây là bức hoạ rất cổ.\n"
	.string "Lớp sơn bị bong tróc chỗ này, chỗ kia.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery:
	.string "Đây là một khung cảnh kỳ lạ với\n"
    .string "hình ảnh kỳ quái và huyền ảo.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman:
	.string "Đây là bức hoạ về POKéMON ngồi\n"
	.string "trên đùi một người phụ nữ xinh đẹp.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon:
	.string "Đây là bức hoạ về POKéMON\n"
	.string "huyền thoại từ rất lâu về trước.\p"
	.string "Tác giả vẽ tranh\n"
	.string "bằng trí tưởng tượng.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon:
	.string "Đây là bức hoạ POKéMON CỎ\n"
    .string "đang đung đưa trong làn gió.\p"
    .string "Dường như nó đang tận hưởng\n"
    .string "sự vuốt ve nhẹ nhàng của gió.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries:
	.string "Đây là bức hoạ về\n"
	.string "TRÁI CÂY ngon miệng.\p"
	.string "Bức hoạ tạo cảm giác thèm ăn!$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica:
	.string "Bản sao của một tác phẩm điêu khắc nổi\p"
    .string "tiếng, miêu tả POKéMON CHIM cổ đại.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone:
	.string "Đây là một QUẢ CẦU POKéMON lớn\n"
    .string "được tạc từ một hòn đá đen.\p"
    .string "Có vẻ như nó từng được dùng trong\n"
    .string "các lễ hội ngày xưa.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText:
	.string "Đây là một tấm bia đá khổng lồ có khắc\n"
    .string "chữ POKéMON và những dòng chữ cỡ nhỏ\l"
    .string "dày đặc của một ngôn ngữ cổ xưa,\l"
    .string "không thể đọc được.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence:
	.string "Hừmmm…\n"
	.string "Những kiệt tác vĩ đại…$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts:
	.string "Chiến đấu với POKéMON rất vui.\n"
    .string "Đồng ý vậy.\p"
    .string "Nhưng xin người đừng quên tình yêu\n"
    .string "dành cho nghệ thuật cao quý.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration:
	.string "BẢO TÀNG NGHỆ THUẬT này… ừm, bạn có thể\n"
    .string "chiêm ngưỡng nhiều bức tranh mỹ miều.\p"
    .string "QUẢN ĐỐC là một người rất tuyệt vời.\p"
    .string "Đối với những người hoạ sĩ như tui,\n"
    .string "cái BẢO TÀNG này là một nguồn cảm hứng.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty:
	.string "Cái cô này xinh ghê!\n"
	.string "Nhìn cổ giống Má quá!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable:
	.string "Con POKéMON này nhìn cưng ghê!\n"
	.string "Giống con trai tui quá!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings:
	.string "Nghe nói BẢO TÀNG NGHỆ THUẬT\n"
	.string "mới có thêm nhiều tranh mới.\p"
	.string "Bởi vậy, tui mới lật đật chạy tới.\p"
	.string "Mà mấy cái tranh mới đó\n"
	.string "ở trên tầng 2 hả?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful:
	.string "Mấy nay, ông QUẢN ĐỐC\n"
	.string "nhìn không vui.\p"
	.string "Chắc ổng có chuyện gì rồi.\n"
	.string "Cá luôn.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings:
	.string "Tui tới để coi tranh rồi\n"
	.string "học hỏi theo.\p"
	.string "Tui có ước mơ, một ngày nào đó,\n"
	.string "tác phẩm của mình được trưng bày ở đây.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination:
	.string "BẢO TÀNG NGHỆ THUẬT giờ đã là\n"
	.string "điểm thu hút khách du lịch rồi.\p"
	.string "Tốt cho TP.BIỂN rồi…\n"
	.string "À không, phải là tốt cho HOENN!\p"
	.string "Cái này tui nghe người ta nói--một\n"
	.string "NHL cô đơn đã mua hết tranh tầng trên.$"

