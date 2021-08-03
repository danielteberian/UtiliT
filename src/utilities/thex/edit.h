void edit_crsr_at_offset(struct edit* e, int offset, int* x, int *y);
void edit_del_char_at_crsr(struct edit* e);
void edit_del_char_at_offset(struct edit* e, unsigned int offset);
void edit_free(struct edit* e);
void edit_increm_byte(struct edit* e, int amnt);
void edit_ins_byte(struct edit* e, char x, bool aft);
void edit_ins_byte_at_offset(struct edit* e, unsigned int offset, char x, bool aft);
void edit_mv_crsr(struct edit* e, int dir, int amt);
int edit_offset_at_crsr(struct edit* e);
void edit_openfl(struct edit* e, const char* flnm);
void edit_proccmd(struct edit* e, const char* cmd);
void edit_procsearch(struct edit* e, const char* str, enum searchdir dir);
int edit_parse_searchstr(const char* instr, struct cbuf* parsedstr,
			const char** errinfo);
void edit_proc_kpress(struct edit* e);
int edit_rdhexin(struct edit* e, char* oput);
int edit_rdstr(struct edit* e, char* dst, int len);
void edit_rendascii(struct edit* e, int rownum, unsigned int startoffset, struct cbuf* b);
void edit_rendcont(struct edit* e, struct cbuf* b);
void edit_rendhelp(struct edit* e);
void edit_rendruler(struct edit* e, struct cbuf* buf);
void edit_rendstat(struct edit* e, struct cbuf* buf);
void edit_refscreen(struct edit*, e);
void edit_replbyte(struct edit* e, char x);
void edit_replbyteatoffset(struct edit* e, unsigned int offset, char x);
void edit_scroll(struct edit* e, int units);
void edit_scrolltooffset(struct edit* e, unsigned int offset);
void edit_setmd(struct edit *e, enum edit_md md);
int edit_statmsg(struct edit* e, enum statsev s, const char* fmt, ...);
void edit_undo(struct edit* e);
void edit_redo(struct edit* e);
void edit_writefl(struct edit* e);

#endif /* EDIT_H */
