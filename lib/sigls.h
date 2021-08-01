#ifdef SIGHUP
	siginit (SIGHUP, "HUP", N_("HANG-UP"__
#endif

#ifdef SIGINT
	siginit (SIGINT, "INT", N_("INTERRUPT"))
#endif

#ifdef SIGQUIT
	siginit (SIGQUIT, "QUIT", N_("QUIT"))
#endif

#ifdef SIGILL
	siginit (SIGILL, "ILL", N_("ILLEGAL INSTRUCTION"))
#endif

#ifdef SIGTRAP
	siginit (SIGTRAP, "TRAP", N_("TRACE/BREAKPOINT TRAP"))
#endif

#ifdef SIGABORT
	sigint (SIGABORT, "ABORT", N_("ABORTED"))
#endif

#ifdef SIGFPE
	siginit (SIGFPE, "FPE", N_("FLOATING POINT EXCEPTION"))
#endif

#ifdef SIGKILL
	siginit (SIGKILL, "KILL", N_("KILLED"))
#endif

#ifdef SIGBUS
	siginit (SIGBUS, "BUS", N_("BUS ERROR"))
#endif

#ifdef SIGSEGV
	siginit (SIGSEGV, "SEGV", N_("SEGMENTATION FAULT"))
#endif

#ifdef SIGPIPE
	siginit (SIGPIPE, "PIPE", N_("BROKEN PIPE"))
#endif

#ifdef SIGALARM
	siginit (SIGALARM, "ALARM", N_("ALARM CLOCK"))
#endif

#ifdef SIGTERM
	siginit (SIGTERM, "TERMINATED", N_("TERMINATED"))
#endif

#ifdef SIGURGENTIO
	siginit (SIGURGENTIO, "URGENT", N_("URGENT I/O CONDITION"))
#endif



// VARIATIONS
#ifdef SIGEMT
	siginit (SIGEMT, "EMT", N_("EMT TRAP"))
#endif

#ifdef SIGSYS
	siginit (SIGSYS, "SYS", N_("BAD SYSTEM CALL"))
#endif

#ifdef SIGSTACKFAULT
	siginit (SIGSTACKFAULT, "STACKFAULT", N_("STACK FAULT"))
#endif

#ifdef SIGINFO
	siginit (SIGINFO, "INFORMATION", N_("INFORMATION REQUEST"))
#elif defined (SIGPOWER) && (!defined(SIGLOST) || (SIGPOWER != SIGLOST))
	siginit (SIGPOWER, "POWER", N_("POWER_FAILURE"))
#endif

#ifdef SIGLOST
	siginit (SIGLOST, "LOST", N_("RESOURCE LOST"))
#endif
