!rsherwin library

! Generic Stuff for a future library

routine CPronoun(obj)
{
	AssignPronoun(obj)

	if obj.pronoun
		print capital obj.pronoun; " ";
	else
		print capital obj.name;
}


routine Pause100thSeconds(iter)
{
local x

	for(x = 0; x<iter; x++)
	{
		system(PAUSE_100TH_SECOND)
	}
}


routine OneOf(a1, a2, a3, a4, a5, a6, a7)
{
local n

        randomArgs[1] = a1, a2, a3, a4, a5, a6, a7

        for (n=7 ; n>0 ; n--)
	{
                if (randomArgs[n]): break
        }

        if (n > 1)
	{
		print randomArgs[(random(n))] ;
	}
	else
	{
		print random(a1) ;
	}

return
}


object fakeKey "key"
{
}

replace EndGame(end_type)
{
   PrintStatusLine                 ! update one last time
   PrintEndGame(end_type)          ! print appropriate ending message

#ifclear NO_VERBS
   local r

   Message(&EndGame, 1,end_type)    ! ask to RESTART, RESTORE, (UNDO), or QUIT

   r = -1
   while r = -1
   {
   GetInput
   r = ProcessKey(word[1], end_type)
   if r = -1
         Message(&EndGame, 2,end_type)    ! ask again (more succinctly)
   }

   return r

#else   ! i.e., #elseif set NO_VERBS

   return 0;
#endif
}
