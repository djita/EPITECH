oFFSET_StgRegTable_rR1 :: Int
oFFSET_StgRegTable_rR1 = 0
oFFSET_StgRegTable_rR2 :: Int
oFFSET_StgRegTable_rR2 = 8
oFFSET_StgRegTable_rR3 :: Int
oFFSET_StgRegTable_rR3 = 16
oFFSET_StgRegTable_rR4 :: Int
oFFSET_StgRegTable_rR4 = 24
oFFSET_StgRegTable_rR5 :: Int
oFFSET_StgRegTable_rR5 = 32
oFFSET_StgRegTable_rR6 :: Int
oFFSET_StgRegTable_rR6 = 40
oFFSET_StgRegTable_rR7 :: Int
oFFSET_StgRegTable_rR7 = 48
oFFSET_StgRegTable_rR8 :: Int
oFFSET_StgRegTable_rR8 = 56
oFFSET_StgRegTable_rR9 :: Int
oFFSET_StgRegTable_rR9 = 64
oFFSET_StgRegTable_rR10 :: Int
oFFSET_StgRegTable_rR10 = 72
oFFSET_StgRegTable_rF1 :: Int
oFFSET_StgRegTable_rF1 = 80
oFFSET_StgRegTable_rF2 :: Int
oFFSET_StgRegTable_rF2 = 84
oFFSET_StgRegTable_rF3 :: Int
oFFSET_StgRegTable_rF3 = 88
oFFSET_StgRegTable_rF4 :: Int
oFFSET_StgRegTable_rF4 = 92
oFFSET_StgRegTable_rD1 :: Int
oFFSET_StgRegTable_rD1 = 96
oFFSET_StgRegTable_rD2 :: Int
oFFSET_StgRegTable_rD2 = 104
oFFSET_StgRegTable_rL1 :: Int
oFFSET_StgRegTable_rL1 = 112
oFFSET_StgRegTable_rSp :: Int
oFFSET_StgRegTable_rSp = 120
oFFSET_StgRegTable_rSpLim :: Int
oFFSET_StgRegTable_rSpLim = 128
oFFSET_StgRegTable_rHp :: Int
oFFSET_StgRegTable_rHp = 136
oFFSET_StgRegTable_rHpLim :: Int
oFFSET_StgRegTable_rHpLim = 144
oFFSET_StgRegTable_rCCCS :: Int
oFFSET_StgRegTable_rCCCS = 152
oFFSET_StgRegTable_rCurrentTSO :: Int
oFFSET_StgRegTable_rCurrentTSO = 160
oFFSET_StgRegTable_rCurrentNursery :: Int
oFFSET_StgRegTable_rCurrentNursery = 176
oFFSET_StgRegTable_rHpAlloc :: Int
oFFSET_StgRegTable_rHpAlloc = 192
oFFSET_StgRegTable_rRet :: Int
oFFSET_StgRegTable_rRet = 200
#define StgRegTable_rRet(__ptr__)  REP_StgRegTable_rRet[__ptr__+OFFSET_StgRegTable_rRet]
oFFSET_StgRegTable_rNursery :: Int
oFFSET_StgRegTable_rNursery = 168
#define StgRegTable_rNursery(__ptr__)  REP_StgRegTable_rNursery[__ptr__+OFFSET_StgRegTable_rNursery]
oFFSET_stgEagerBlackholeInfo :: Int
oFFSET_stgEagerBlackholeInfo = 18446744073709551592
oFFSET_stgGCEnter1 :: Int
oFFSET_stgGCEnter1 = 18446744073709551600
oFFSET_stgGCFun :: Int
oFFSET_stgGCFun = 18446744073709551608
oFFSET_Capability_r :: Int
oFFSET_Capability_r = 24
oFFSET_Capability_lock :: Int
oFFSET_Capability_lock = 328
oFFSET_Capability_no :: Int
oFFSET_Capability_no = 232
#define Capability_no(__ptr__)  REP_Capability_no[__ptr__+OFFSET_Capability_no]
oFFSET_Capability_mut_lists :: Int
oFFSET_Capability_mut_lists = 280
#define Capability_mut_lists(__ptr__)  REP_Capability_mut_lists[__ptr__+OFFSET_Capability_mut_lists]
oFFSET_Capability_context_switch :: Int
oFFSET_Capability_context_switch = 304
#define Capability_context_switch(__ptr__)  REP_Capability_context_switch[__ptr__+OFFSET_Capability_context_switch]
oFFSET_Capability_interrupt :: Int
oFFSET_Capability_interrupt = 308
#define Capability_interrupt(__ptr__)  REP_Capability_interrupt[__ptr__+OFFSET_Capability_interrupt]
oFFSET_Capability_sparks :: Int
oFFSET_Capability_sparks = 392
#define Capability_sparks(__ptr__)  REP_Capability_sparks[__ptr__+OFFSET_Capability_sparks]
oFFSET_bdescr_start :: Int
oFFSET_bdescr_start = 0
#define bdescr_start(__ptr__)  REP_bdescr_start[__ptr__+OFFSET_bdescr_start]
oFFSET_bdescr_free :: Int
oFFSET_bdescr_free = 8
#define bdescr_free(__ptr__)  REP_bdescr_free[__ptr__+OFFSET_bdescr_free]
oFFSET_bdescr_blocks :: Int
oFFSET_bdescr_blocks = 48
#define bdescr_blocks(__ptr__)  REP_bdescr_blocks[__ptr__+OFFSET_bdescr_blocks]
oFFSET_bdescr_gen_no :: Int
oFFSET_bdescr_gen_no = 40
#define bdescr_gen_no(__ptr__)  REP_bdescr_gen_no[__ptr__+OFFSET_bdescr_gen_no]
oFFSET_bdescr_link :: Int
oFFSET_bdescr_link = 16
#define bdescr_link(__ptr__)  REP_bdescr_link[__ptr__+OFFSET_bdescr_link]
sIZEOF_generation :: Int
sIZEOF_generation = 304
oFFSET_generation_n_new_large_words :: Int
oFFSET_generation_n_new_large_words = 48
#define generation_n_new_large_words(__ptr__)  REP_generation_n_new_large_words[__ptr__+OFFSET_generation_n_new_large_words]
sIZEOF_CostCentreStack :: Int
sIZEOF_CostCentreStack = 96
oFFSET_CostCentreStack_ccsID :: Int
oFFSET_CostCentreStack_ccsID = 0
#define CostCentreStack_ccsID(__ptr__)  REP_CostCentreStack_ccsID[__ptr__+OFFSET_CostCentreStack_ccsID]
oFFSET_CostCentreStack_mem_alloc :: Int
oFFSET_CostCentreStack_mem_alloc = 72
#define CostCentreStack_mem_alloc(__ptr__)  REP_CostCentreStack_mem_alloc[__ptr__+OFFSET_CostCentreStack_mem_alloc]
oFFSET_CostCentreStack_scc_count :: Int
oFFSET_CostCentreStack_scc_count = 48
#define CostCentreStack_scc_count(__ptr__)  REP_CostCentreStack_scc_count[__ptr__+OFFSET_CostCentreStack_scc_count]
oFFSET_CostCentreStack_prevStack :: Int
oFFSET_CostCentreStack_prevStack = 16
#define CostCentreStack_prevStack(__ptr__)  REP_CostCentreStack_prevStack[__ptr__+OFFSET_CostCentreStack_prevStack]
oFFSET_CostCentre_ccID :: Int
oFFSET_CostCentre_ccID = 0
#define CostCentre_ccID(__ptr__)  REP_CostCentre_ccID[__ptr__+OFFSET_CostCentre_ccID]
oFFSET_CostCentre_link :: Int
oFFSET_CostCentre_link = 56
#define CostCentre_link(__ptr__)  REP_CostCentre_link[__ptr__+OFFSET_CostCentre_link]
oFFSET_StgHeader_info :: Int
oFFSET_StgHeader_info = 0
#define StgHeader_info(__ptr__)  REP_StgHeader_info[__ptr__+OFFSET_StgHeader_info]
oFFSET_StgHeader_ccs :: Int
oFFSET_StgHeader_ccs = 8
#define StgHeader_ccs(__ptr__)  REP_StgHeader_ccs[__ptr__+OFFSET_StgHeader_ccs]
oFFSET_StgHeader_ldvw :: Int
oFFSET_StgHeader_ldvw = 16
#define StgHeader_ldvw(__ptr__)  REP_StgHeader_ldvw[__ptr__+OFFSET_StgHeader_ldvw]
sIZEOF_StgSMPThunkHeader :: Int
sIZEOF_StgSMPThunkHeader = 8
oFFSET_StgClosure_payload :: Int
oFFSET_StgClosure_payload = 0
#define StgClosure_payload(__ptr__,__ix__)  W_[__ptr__+SIZEOF_StgHeader+OFFSET_StgClosure_payload + WDS(__ix__)]
oFFSET_StgEntCounter_allocs :: Int
oFFSET_StgEntCounter_allocs = 48
#define StgEntCounter_allocs(__ptr__)  REP_StgEntCounter_allocs[__ptr__+OFFSET_StgEntCounter_allocs]
oFFSET_StgEntCounter_registeredp :: Int
oFFSET_StgEntCounter_registeredp = 0
#define StgEntCounter_registeredp(__ptr__)  REP_StgEntCounter_registeredp[__ptr__+OFFSET_StgEntCounter_registeredp]
oFFSET_StgEntCounter_link :: Int
oFFSET_StgEntCounter_link = 56
#define StgEntCounter_link(__ptr__)  REP_StgEntCounter_link[__ptr__+OFFSET_StgEntCounter_link]
oFFSET_StgEntCounter_entry_count :: Int
oFFSET_StgEntCounter_entry_count = 40
#define StgEntCounter_entry_count(__ptr__)  REP_StgEntCounter_entry_count[__ptr__+OFFSET_StgEntCounter_entry_count]
sIZEOF_StgUpdateFrame_NoHdr :: Int
sIZEOF_StgUpdateFrame_NoHdr = 8
sIZEOF_StgCatchFrame_NoHdr :: Int
sIZEOF_StgCatchFrame_NoHdr = 16
sIZEOF_StgStopFrame_NoHdr :: Int
sIZEOF_StgStopFrame_NoHdr = 0
sIZEOF_StgMutArrPtrs_NoHdr :: Int
sIZEOF_StgMutArrPtrs_NoHdr = 16
oFFSET_StgMutArrPtrs_ptrs :: Int
oFFSET_StgMutArrPtrs_ptrs = 0
#define StgMutArrPtrs_ptrs(__ptr__)  REP_StgMutArrPtrs_ptrs[__ptr__+SIZEOF_StgHeader+OFFSET_StgMutArrPtrs_ptrs]
oFFSET_StgMutArrPtrs_size :: Int
oFFSET_StgMutArrPtrs_size = 8
#define StgMutArrPtrs_size(__ptr__)  REP_StgMutArrPtrs_size[__ptr__+SIZEOF_StgHeader+OFFSET_StgMutArrPtrs_size]
sIZEOF_StgArrWords_NoHdr :: Int
sIZEOF_StgArrWords_NoHdr = 8
oFFSET_StgArrWords_bytes :: Int
oFFSET_StgArrWords_bytes = 0
#define StgArrWords_bytes(__ptr__)  REP_StgArrWords_bytes[__ptr__+SIZEOF_StgHeader+OFFSET_StgArrWords_bytes]
oFFSET_StgArrWords_payload :: Int
oFFSET_StgArrWords_payload = 8
#define StgArrWords_payload(__ptr__,__ix__)  W_[__ptr__+SIZEOF_StgHeader+OFFSET_StgArrWords_payload + WDS(__ix__)]
oFFSET_StgTSO__link :: Int
oFFSET_StgTSO__link = 0
#define StgTSO__link(__ptr__)  REP_StgTSO__link[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO__link]
oFFSET_StgTSO_global_link :: Int
oFFSET_StgTSO_global_link = 8
#define StgTSO_global_link(__ptr__)  REP_StgTSO_global_link[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_global_link]
oFFSET_StgTSO_what_next :: Int
oFFSET_StgTSO_what_next = 24
#define StgTSO_what_next(__ptr__)  REP_StgTSO_what_next[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_what_next]
oFFSET_StgTSO_why_blocked :: Int
oFFSET_StgTSO_why_blocked = 26
#define StgTSO_why_blocked(__ptr__)  REP_StgTSO_why_blocked[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_why_blocked]
oFFSET_StgTSO_block_info :: Int
oFFSET_StgTSO_block_info = 32
#define StgTSO_block_info(__ptr__)  REP_StgTSO_block_info[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_block_info]
oFFSET_StgTSO_blocked_exceptions :: Int
oFFSET_StgTSO_blocked_exceptions = 80
#define StgTSO_blocked_exceptions(__ptr__)  REP_StgTSO_blocked_exceptions[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_blocked_exceptions]
oFFSET_StgTSO_id :: Int
oFFSET_StgTSO_id = 40
#define StgTSO_id(__ptr__)  REP_StgTSO_id[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_id]
oFFSET_StgTSO_cap :: Int
oFFSET_StgTSO_cap = 64
#define StgTSO_cap(__ptr__)  REP_StgTSO_cap[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_cap]
oFFSET_StgTSO_saved_errno :: Int
oFFSET_StgTSO_saved_errno = 44
#define StgTSO_saved_errno(__ptr__)  REP_StgTSO_saved_errno[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_saved_errno]
oFFSET_StgTSO_trec :: Int
oFFSET_StgTSO_trec = 72
#define StgTSO_trec(__ptr__)  REP_StgTSO_trec[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_trec]
oFFSET_StgTSO_flags :: Int
oFFSET_StgTSO_flags = 28
#define StgTSO_flags(__ptr__)  REP_StgTSO_flags[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_flags]
oFFSET_StgTSO_dirty :: Int
oFFSET_StgTSO_dirty = 48
#define StgTSO_dirty(__ptr__)  REP_StgTSO_dirty[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_dirty]
oFFSET_StgTSO_bq :: Int
oFFSET_StgTSO_bq = 88
#define StgTSO_bq(__ptr__)  REP_StgTSO_bq[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_bq]
oFFSET_StgTSO_cccs :: Int
oFFSET_StgTSO_cccs = 96
#define StgTSO_cccs(__ptr__)  REP_StgTSO_cccs[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_cccs]
oFFSET_StgTSO_stackobj :: Int
oFFSET_StgTSO_stackobj = 16
#define StgTSO_stackobj(__ptr__)  REP_StgTSO_stackobj[__ptr__+SIZEOF_StgHeader+OFFSET_StgTSO_stackobj]
oFFSET_StgStack_sp :: Int
oFFSET_StgStack_sp = 8
#define StgStack_sp(__ptr__)  REP_StgStack_sp[__ptr__+SIZEOF_StgHeader+OFFSET_StgStack_sp]
oFFSET_StgStack_stack :: Int
oFFSET_StgStack_stack = 16
oFFSET_StgStack_stack_size :: Int
oFFSET_StgStack_stack_size = 0
#define StgStack_stack_size(__ptr__)  REP_StgStack_stack_size[__ptr__+SIZEOF_StgHeader+OFFSET_StgStack_stack_size]
oFFSET_StgStack_dirty :: Int
oFFSET_StgStack_dirty = 4
#define StgStack_dirty(__ptr__)  REP_StgStack_dirty[__ptr__+SIZEOF_StgHeader+OFFSET_StgStack_dirty]
sIZEOF_StgTSOProfInfo :: Int
sIZEOF_StgTSOProfInfo = 8
#ifdef PROFILING
#define SIZEOF_OPT_StgTSOProfInfo SIZEOF_StgTSOProfInfo
#else
#define SIZEOF_OPT_StgTSOProfInfo 0
#endif

oFFSET_StgUpdateFrame_updatee :: Int
oFFSET_StgUpdateFrame_updatee = 0
#define StgUpdateFrame_updatee(__ptr__)  REP_StgUpdateFrame_updatee[__ptr__+SIZEOF_StgHeader+OFFSET_StgUpdateFrame_updatee]
oFFSET_StgCatchFrame_handler :: Int
oFFSET_StgCatchFrame_handler = 8
#define StgCatchFrame_handler(__ptr__)  REP_StgCatchFrame_handler[__ptr__+SIZEOF_StgHeader+OFFSET_StgCatchFrame_handler]
oFFSET_StgCatchFrame_exceptions_blocked :: Int
oFFSET_StgCatchFrame_exceptions_blocked = 0
#define StgCatchFrame_exceptions_blocked(__ptr__)  REP_StgCatchFrame_exceptions_blocked[__ptr__+SIZEOF_StgHeader+OFFSET_StgCatchFrame_exceptions_blocked]
sIZEOF_StgPAP_NoHdr :: Int
sIZEOF_StgPAP_NoHdr = 16
oFFSET_StgPAP_n_args :: Int
oFFSET_StgPAP_n_args = 4
#define StgPAP_n_args(__ptr__)  REP_StgPAP_n_args[__ptr__+SIZEOF_StgHeader+OFFSET_StgPAP_n_args]
oFFSET_StgPAP_fun :: Int
oFFSET_StgPAP_fun = 8
#define StgPAP_fun(__ptr__)  REP_StgPAP_fun[__ptr__+SIZEOF_StgHeader+OFFSET_StgPAP_fun]
oFFSET_StgPAP_arity :: Int
oFFSET_StgPAP_arity = 0
#define StgPAP_arity(__ptr__)  REP_StgPAP_arity[__ptr__+SIZEOF_StgHeader+OFFSET_StgPAP_arity]
oFFSET_StgPAP_payload :: Int
oFFSET_StgPAP_payload = 16
#define StgPAP_payload(__ptr__,__ix__)  W_[__ptr__+SIZEOF_StgHeader+OFFSET_StgPAP_payload + WDS(__ix__)]
sIZEOF_StgAP_NoThunkHdr :: Int
sIZEOF_StgAP_NoThunkHdr = 16
sIZEOF_StgAP_NoHdr :: Int
sIZEOF_StgAP_NoHdr = 24
oFFSET_StgAP_n_args :: Int
oFFSET_StgAP_n_args = 12
#define StgAP_n_args(__ptr__)  REP_StgAP_n_args[__ptr__+SIZEOF_StgHeader+OFFSET_StgAP_n_args]
oFFSET_StgAP_fun :: Int
oFFSET_StgAP_fun = 16
#define StgAP_fun(__ptr__)  REP_StgAP_fun[__ptr__+SIZEOF_StgHeader+OFFSET_StgAP_fun]
oFFSET_StgAP_payload :: Int
oFFSET_StgAP_payload = 24
#define StgAP_payload(__ptr__,__ix__)  W_[__ptr__+SIZEOF_StgHeader+OFFSET_StgAP_payload + WDS(__ix__)]
sIZEOF_StgAP_STACK_NoThunkHdr :: Int
sIZEOF_StgAP_STACK_NoThunkHdr = 16
sIZEOF_StgAP_STACK_NoHdr :: Int
sIZEOF_StgAP_STACK_NoHdr = 24
oFFSET_StgAP_STACK_size :: Int
oFFSET_StgAP_STACK_size = 8
#define StgAP_STACK_size(__ptr__)  REP_StgAP_STACK_size[__ptr__+SIZEOF_StgHeader+OFFSET_StgAP_STACK_size]
oFFSET_StgAP_STACK_fun :: Int
oFFSET_StgAP_STACK_fun = 16
#define StgAP_STACK_fun(__ptr__)  REP_StgAP_STACK_fun[__ptr__+SIZEOF_StgHeader+OFFSET_StgAP_STACK_fun]
oFFSET_StgAP_STACK_payload :: Int
oFFSET_StgAP_STACK_payload = 24
#define StgAP_STACK_payload(__ptr__,__ix__)  W_[__ptr__+SIZEOF_StgHeader+OFFSET_StgAP_STACK_payload + WDS(__ix__)]
sIZEOF_StgSelector_NoThunkHdr :: Int
sIZEOF_StgSelector_NoThunkHdr = 8
sIZEOF_StgSelector_NoHdr :: Int
sIZEOF_StgSelector_NoHdr = 16
oFFSET_StgInd_indirectee :: Int
oFFSET_StgInd_indirectee = 0
#define StgInd_indirectee(__ptr__)  REP_StgInd_indirectee[__ptr__+SIZEOF_StgHeader+OFFSET_StgInd_indirectee]
sIZEOF_StgMutVar_NoHdr :: Int
sIZEOF_StgMutVar_NoHdr = 8
oFFSET_StgMutVar_var :: Int
oFFSET_StgMutVar_var = 0
#define StgMutVar_var(__ptr__)  REP_StgMutVar_var[__ptr__+SIZEOF_StgHeader+OFFSET_StgMutVar_var]
sIZEOF_StgAtomicallyFrame_NoHdr :: Int
sIZEOF_StgAtomicallyFrame_NoHdr = 24
oFFSET_StgAtomicallyFrame_code :: Int
oFFSET_StgAtomicallyFrame_code = 0
#define StgAtomicallyFrame_code(__ptr__)  REP_StgAtomicallyFrame_code[__ptr__+SIZEOF_StgHeader+OFFSET_StgAtomicallyFrame_code]
oFFSET_StgAtomicallyFrame_next_invariant_to_check :: Int
oFFSET_StgAtomicallyFrame_next_invariant_to_check = 8
#define StgAtomicallyFrame_next_invariant_to_check(__ptr__)  REP_StgAtomicallyFrame_next_invariant_to_check[__ptr__+SIZEOF_StgHeader+OFFSET_StgAtomicallyFrame_next_invariant_to_check]
oFFSET_StgAtomicallyFrame_result :: Int
oFFSET_StgAtomicallyFrame_result = 16
#define StgAtomicallyFrame_result(__ptr__)  REP_StgAtomicallyFrame_result[__ptr__+SIZEOF_StgHeader+OFFSET_StgAtomicallyFrame_result]
oFFSET_StgInvariantCheckQueue_invariant :: Int
oFFSET_StgInvariantCheckQueue_invariant = 0
#define StgInvariantCheckQueue_invariant(__ptr__)  REP_StgInvariantCheckQueue_invariant[__ptr__+SIZEOF_StgHeader+OFFSET_StgInvariantCheckQueue_invariant]
oFFSET_StgInvariantCheckQueue_my_execution :: Int
oFFSET_StgInvariantCheckQueue_my_execution = 8
#define StgInvariantCheckQueue_my_execution(__ptr__)  REP_StgInvariantCheckQueue_my_execution[__ptr__+SIZEOF_StgHeader+OFFSET_StgInvariantCheckQueue_my_execution]
oFFSET_StgInvariantCheckQueue_next_queue_entry :: Int
oFFSET_StgInvariantCheckQueue_next_queue_entry = 16
#define StgInvariantCheckQueue_next_queue_entry(__ptr__)  REP_StgInvariantCheckQueue_next_queue_entry[__ptr__+SIZEOF_StgHeader+OFFSET_StgInvariantCheckQueue_next_queue_entry]
oFFSET_StgAtomicInvariant_code :: Int
oFFSET_StgAtomicInvariant_code = 0
#define StgAtomicInvariant_code(__ptr__)  REP_StgAtomicInvariant_code[__ptr__+SIZEOF_StgHeader+OFFSET_StgAtomicInvariant_code]
oFFSET_StgTRecHeader_enclosing_trec :: Int
oFFSET_StgTRecHeader_enclosing_trec = 0
#define StgTRecHeader_enclosing_trec(__ptr__)  REP_StgTRecHeader_enclosing_trec[__ptr__+SIZEOF_StgHeader+OFFSET_StgTRecHeader_enclosing_trec]
sIZEOF_StgCatchSTMFrame_NoHdr :: Int
sIZEOF_StgCatchSTMFrame_NoHdr = 16
oFFSET_StgCatchSTMFrame_handler :: Int
oFFSET_StgCatchSTMFrame_handler = 8
#define StgCatchSTMFrame_handler(__ptr__)  REP_StgCatchSTMFrame_handler[__ptr__+SIZEOF_StgHeader+OFFSET_StgCatchSTMFrame_handler]
oFFSET_StgCatchSTMFrame_code :: Int
oFFSET_StgCatchSTMFrame_code = 0
#define StgCatchSTMFrame_code(__ptr__)  REP_StgCatchSTMFrame_code[__ptr__+SIZEOF_StgHeader+OFFSET_StgCatchSTMFrame_code]
sIZEOF_StgCatchRetryFrame_NoHdr :: Int
sIZEOF_StgCatchRetryFrame_NoHdr = 24
oFFSET_StgCatchRetryFrame_running_alt_code :: Int
oFFSET_StgCatchRetryFrame_running_alt_code = 0
#define StgCatchRetryFrame_running_alt_code(__ptr__)  REP_StgCatchRetryFrame_running_alt_code[__ptr__+SIZEOF_StgHeader+OFFSET_StgCatchRetryFrame_running_alt_code]
oFFSET_StgCatchRetryFrame_first_code :: Int
oFFSET_StgCatchRetryFrame_first_code = 8
#define StgCatchRetryFrame_first_code(__ptr__)  REP_StgCatchRetryFrame_first_code[__ptr__+SIZEOF_StgHeader+OFFSET_StgCatchRetryFrame_first_code]
oFFSET_StgCatchRetryFrame_alt_code :: Int
oFFSET_StgCatchRetryFrame_alt_code = 16
#define StgCatchRetryFrame_alt_code(__ptr__)  REP_StgCatchRetryFrame_alt_code[__ptr__+SIZEOF_StgHeader+OFFSET_StgCatchRetryFrame_alt_code]
oFFSET_StgTVarWatchQueue_closure :: Int
oFFSET_StgTVarWatchQueue_closure = 0
#define StgTVarWatchQueue_closure(__ptr__)  REP_StgTVarWatchQueue_closure[__ptr__+SIZEOF_StgHeader+OFFSET_StgTVarWatchQueue_closure]
oFFSET_StgTVarWatchQueue_next_queue_entry :: Int
oFFSET_StgTVarWatchQueue_next_queue_entry = 8
#define StgTVarWatchQueue_next_queue_entry(__ptr__)  REP_StgTVarWatchQueue_next_queue_entry[__ptr__+SIZEOF_StgHeader+OFFSET_StgTVarWatchQueue_next_queue_entry]
oFFSET_StgTVarWatchQueue_prev_queue_entry :: Int
oFFSET_StgTVarWatchQueue_prev_queue_entry = 16
#define StgTVarWatchQueue_prev_queue_entry(__ptr__)  REP_StgTVarWatchQueue_prev_queue_entry[__ptr__+SIZEOF_StgHeader+OFFSET_StgTVarWatchQueue_prev_queue_entry]
oFFSET_StgTVar_current_value :: Int
oFFSET_StgTVar_current_value = 0
#define StgTVar_current_value(__ptr__)  REP_StgTVar_current_value[__ptr__+SIZEOF_StgHeader+OFFSET_StgTVar_current_value]
sIZEOF_StgWeak_NoHdr :: Int
sIZEOF_StgWeak_NoHdr = 40
oFFSET_StgWeak_link :: Int
oFFSET_StgWeak_link = 32
#define StgWeak_link(__ptr__)  REP_StgWeak_link[__ptr__+SIZEOF_StgHeader+OFFSET_StgWeak_link]
oFFSET_StgWeak_key :: Int
oFFSET_StgWeak_key = 8
#define StgWeak_key(__ptr__)  REP_StgWeak_key[__ptr__+SIZEOF_StgHeader+OFFSET_StgWeak_key]
oFFSET_StgWeak_value :: Int
oFFSET_StgWeak_value = 16
#define StgWeak_value(__ptr__)  REP_StgWeak_value[__ptr__+SIZEOF_StgHeader+OFFSET_StgWeak_value]
oFFSET_StgWeak_finalizer :: Int
oFFSET_StgWeak_finalizer = 24
#define StgWeak_finalizer(__ptr__)  REP_StgWeak_finalizer[__ptr__+SIZEOF_StgHeader+OFFSET_StgWeak_finalizer]
oFFSET_StgWeak_cfinalizer :: Int
oFFSET_StgWeak_cfinalizer = 0
#define StgWeak_cfinalizer(__ptr__)  REP_StgWeak_cfinalizer[__ptr__+SIZEOF_StgHeader+OFFSET_StgWeak_cfinalizer]
sIZEOF_StgDeadWeak_NoHdr :: Int
sIZEOF_StgDeadWeak_NoHdr = 8
oFFSET_StgDeadWeak_link :: Int
oFFSET_StgDeadWeak_link = 0
#define StgDeadWeak_link(__ptr__)  REP_StgDeadWeak_link[__ptr__+SIZEOF_StgHeader+OFFSET_StgDeadWeak_link]
sIZEOF_StgMVar_NoHdr :: Int
sIZEOF_StgMVar_NoHdr = 24
oFFSET_StgMVar_head :: Int
oFFSET_StgMVar_head = 0
#define StgMVar_head(__ptr__)  REP_StgMVar_head[__ptr__+SIZEOF_StgHeader+OFFSET_StgMVar_head]
oFFSET_StgMVar_tail :: Int
oFFSET_StgMVar_tail = 8
#define StgMVar_tail(__ptr__)  REP_StgMVar_tail[__ptr__+SIZEOF_StgHeader+OFFSET_StgMVar_tail]
oFFSET_StgMVar_value :: Int
oFFSET_StgMVar_value = 16
#define StgMVar_value(__ptr__)  REP_StgMVar_value[__ptr__+SIZEOF_StgHeader+OFFSET_StgMVar_value]
sIZEOF_StgMVarTSOQueue_NoHdr :: Int
sIZEOF_StgMVarTSOQueue_NoHdr = 16
oFFSET_StgMVarTSOQueue_link :: Int
oFFSET_StgMVarTSOQueue_link = 0
#define StgMVarTSOQueue_link(__ptr__)  REP_StgMVarTSOQueue_link[__ptr__+SIZEOF_StgHeader+OFFSET_StgMVarTSOQueue_link]
oFFSET_StgMVarTSOQueue_tso :: Int
oFFSET_StgMVarTSOQueue_tso = 8
#define StgMVarTSOQueue_tso(__ptr__)  REP_StgMVarTSOQueue_tso[__ptr__+SIZEOF_StgHeader+OFFSET_StgMVarTSOQueue_tso]
sIZEOF_StgBCO_NoHdr :: Int
sIZEOF_StgBCO_NoHdr = 32
oFFSET_StgBCO_instrs :: Int
oFFSET_StgBCO_instrs = 0
#define StgBCO_instrs(__ptr__)  REP_StgBCO_instrs[__ptr__+SIZEOF_StgHeader+OFFSET_StgBCO_instrs]
oFFSET_StgBCO_literals :: Int
oFFSET_StgBCO_literals = 8
#define StgBCO_literals(__ptr__)  REP_StgBCO_literals[__ptr__+SIZEOF_StgHeader+OFFSET_StgBCO_literals]
oFFSET_StgBCO_ptrs :: Int
oFFSET_StgBCO_ptrs = 16
#define StgBCO_ptrs(__ptr__)  REP_StgBCO_ptrs[__ptr__+SIZEOF_StgHeader+OFFSET_StgBCO_ptrs]
oFFSET_StgBCO_arity :: Int
oFFSET_StgBCO_arity = 24
#define StgBCO_arity(__ptr__)  REP_StgBCO_arity[__ptr__+SIZEOF_StgHeader+OFFSET_StgBCO_arity]
oFFSET_StgBCO_size :: Int
oFFSET_StgBCO_size = 28
#define StgBCO_size(__ptr__)  REP_StgBCO_size[__ptr__+SIZEOF_StgHeader+OFFSET_StgBCO_size]
oFFSET_StgBCO_bitmap :: Int
oFFSET_StgBCO_bitmap = 32
#define StgBCO_bitmap(__ptr__,__ix__)  W_[__ptr__+SIZEOF_StgHeader+OFFSET_StgBCO_bitmap + WDS(__ix__)]
sIZEOF_StgStableName_NoHdr :: Int
sIZEOF_StgStableName_NoHdr = 8
oFFSET_StgStableName_sn :: Int
oFFSET_StgStableName_sn = 0
#define StgStableName_sn(__ptr__)  REP_StgStableName_sn[__ptr__+SIZEOF_StgHeader+OFFSET_StgStableName_sn]
sIZEOF_StgBlockingQueue_NoHdr :: Int
sIZEOF_StgBlockingQueue_NoHdr = 32
oFFSET_StgBlockingQueue_bh :: Int
oFFSET_StgBlockingQueue_bh = 8
#define StgBlockingQueue_bh(__ptr__)  REP_StgBlockingQueue_bh[__ptr__+SIZEOF_StgHeader+OFFSET_StgBlockingQueue_bh]
oFFSET_StgBlockingQueue_owner :: Int
oFFSET_StgBlockingQueue_owner = 16
#define StgBlockingQueue_owner(__ptr__)  REP_StgBlockingQueue_owner[__ptr__+SIZEOF_StgHeader+OFFSET_StgBlockingQueue_owner]
oFFSET_StgBlockingQueue_queue :: Int
oFFSET_StgBlockingQueue_queue = 24
#define StgBlockingQueue_queue(__ptr__)  REP_StgBlockingQueue_queue[__ptr__+SIZEOF_StgHeader+OFFSET_StgBlockingQueue_queue]
oFFSET_StgBlockingQueue_link :: Int
oFFSET_StgBlockingQueue_link = 0
#define StgBlockingQueue_link(__ptr__)  REP_StgBlockingQueue_link[__ptr__+SIZEOF_StgHeader+OFFSET_StgBlockingQueue_link]
sIZEOF_MessageBlackHole_NoHdr :: Int
sIZEOF_MessageBlackHole_NoHdr = 24
oFFSET_MessageBlackHole_link :: Int
oFFSET_MessageBlackHole_link = 0
#define MessageBlackHole_link(__ptr__)  REP_MessageBlackHole_link[__ptr__+SIZEOF_StgHeader+OFFSET_MessageBlackHole_link]
oFFSET_MessageBlackHole_tso :: Int
oFFSET_MessageBlackHole_tso = 8
#define MessageBlackHole_tso(__ptr__)  REP_MessageBlackHole_tso[__ptr__+SIZEOF_StgHeader+OFFSET_MessageBlackHole_tso]
oFFSET_MessageBlackHole_bh :: Int
oFFSET_MessageBlackHole_bh = 16
#define MessageBlackHole_bh(__ptr__)  REP_MessageBlackHole_bh[__ptr__+SIZEOF_StgHeader+OFFSET_MessageBlackHole_bh]
oFFSET_RtsFlags_ProfFlags_showCCSOnException :: Int
oFFSET_RtsFlags_ProfFlags_showCCSOnException = 256
#define RtsFlags_ProfFlags_showCCSOnException(__ptr__)  REP_RtsFlags_ProfFlags_showCCSOnException[__ptr__+OFFSET_RtsFlags_ProfFlags_showCCSOnException]
oFFSET_RtsFlags_DebugFlags_apply :: Int
oFFSET_RtsFlags_DebugFlags_apply = 200
#define RtsFlags_DebugFlags_apply(__ptr__)  REP_RtsFlags_DebugFlags_apply[__ptr__+OFFSET_RtsFlags_DebugFlags_apply]
oFFSET_RtsFlags_DebugFlags_sanity :: Int
oFFSET_RtsFlags_DebugFlags_sanity = 184
#define RtsFlags_DebugFlags_sanity(__ptr__)  REP_RtsFlags_DebugFlags_sanity[__ptr__+OFFSET_RtsFlags_DebugFlags_sanity]
oFFSET_RtsFlags_DebugFlags_weak :: Int
oFFSET_RtsFlags_DebugFlags_weak = 168
#define RtsFlags_DebugFlags_weak(__ptr__)  REP_RtsFlags_DebugFlags_weak[__ptr__+OFFSET_RtsFlags_DebugFlags_weak]
oFFSET_RtsFlags_GcFlags_initialStkSize :: Int
oFFSET_RtsFlags_GcFlags_initialStkSize = 16
#define RtsFlags_GcFlags_initialStkSize(__ptr__)  REP_RtsFlags_GcFlags_initialStkSize[__ptr__+OFFSET_RtsFlags_GcFlags_initialStkSize]
oFFSET_RtsFlags_MiscFlags_tickInterval :: Int
oFFSET_RtsFlags_MiscFlags_tickInterval = 136
#define RtsFlags_MiscFlags_tickInterval(__ptr__)  REP_RtsFlags_MiscFlags_tickInterval[__ptr__+OFFSET_RtsFlags_MiscFlags_tickInterval]
sIZEOF_StgFunInfoExtraFwd :: Int
sIZEOF_StgFunInfoExtraFwd = 32
oFFSET_StgFunInfoExtraFwd_slow_apply :: Int
oFFSET_StgFunInfoExtraFwd_slow_apply = 24
#define StgFunInfoExtraFwd_slow_apply(__ptr__)  REP_StgFunInfoExtraFwd_slow_apply[__ptr__+OFFSET_StgFunInfoExtraFwd_slow_apply]
oFFSET_StgFunInfoExtraFwd_fun_type :: Int
oFFSET_StgFunInfoExtraFwd_fun_type = 0
#define StgFunInfoExtraFwd_fun_type(__ptr__)  REP_StgFunInfoExtraFwd_fun_type[__ptr__+OFFSET_StgFunInfoExtraFwd_fun_type]
oFFSET_StgFunInfoExtraFwd_arity :: Int
oFFSET_StgFunInfoExtraFwd_arity = 4
#define StgFunInfoExtraFwd_arity(__ptr__)  REP_StgFunInfoExtraFwd_arity[__ptr__+OFFSET_StgFunInfoExtraFwd_arity]
oFFSET_StgFunInfoExtraFwd_bitmap :: Int
oFFSET_StgFunInfoExtraFwd_bitmap = 16
#define StgFunInfoExtraFwd_bitmap(__ptr__)  REP_StgFunInfoExtraFwd_bitmap[__ptr__+OFFSET_StgFunInfoExtraFwd_bitmap]
sIZEOF_StgFunInfoExtraRev :: Int
sIZEOF_StgFunInfoExtraRev = 32
oFFSET_StgFunInfoExtraRev_slow_apply_offset :: Int
oFFSET_StgFunInfoExtraRev_slow_apply_offset = 0
#define StgFunInfoExtraRev_slow_apply_offset(__ptr__)  REP_StgFunInfoExtraRev_slow_apply_offset[__ptr__+OFFSET_StgFunInfoExtraRev_slow_apply_offset]
oFFSET_StgFunInfoExtraRev_fun_type :: Int
oFFSET_StgFunInfoExtraRev_fun_type = 24
#define StgFunInfoExtraRev_fun_type(__ptr__)  REP_StgFunInfoExtraRev_fun_type[__ptr__+OFFSET_StgFunInfoExtraRev_fun_type]
oFFSET_StgFunInfoExtraRev_arity :: Int
oFFSET_StgFunInfoExtraRev_arity = 28
#define StgFunInfoExtraRev_arity(__ptr__)  REP_StgFunInfoExtraRev_arity[__ptr__+OFFSET_StgFunInfoExtraRev_arity]
oFFSET_StgFunInfoExtraRev_bitmap :: Int
oFFSET_StgFunInfoExtraRev_bitmap = 8
#define StgFunInfoExtraRev_bitmap(__ptr__)  REP_StgFunInfoExtraRev_bitmap[__ptr__+OFFSET_StgFunInfoExtraRev_bitmap]
oFFSET_StgLargeBitmap_size :: Int
oFFSET_StgLargeBitmap_size = 0
#define StgLargeBitmap_size(__ptr__)  REP_StgLargeBitmap_size[__ptr__+OFFSET_StgLargeBitmap_size]
oFFSET_StgLargeBitmap_bitmap :: Int
oFFSET_StgLargeBitmap_bitmap = 8
sIZEOF_snEntry :: Int
sIZEOF_snEntry = 32
oFFSET_snEntry_sn_obj :: Int
oFFSET_snEntry_sn_obj = 24
#define snEntry_sn_obj(__ptr__)  REP_snEntry_sn_obj[__ptr__+OFFSET_snEntry_sn_obj]
oFFSET_snEntry_addr :: Int
oFFSET_snEntry_addr = 0
#define snEntry_addr(__ptr__)  REP_snEntry_addr[__ptr__+OFFSET_snEntry_addr]
