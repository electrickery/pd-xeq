/* Copyright (c) 1997-2002 Miller Puckette and others.
* For information on usage and redistribution, and for a DISCLAIMER OF ALL
* WARRANTIES, see the file, "LICENSE.txt," in this distribution.  */

#ifndef __DICT_H__
#define __DICT_H__

typedef struct _dict
{
    size_t      d_hashsize;
    t_symbol  **d_hashtable;
    t_class    *d_bindlist_class;
} t_dict;

typedef int (*t_dict_hook)(t_pd *x, void *arg);

t_dict *dict_new(size_t hashsize);
void dict_free(t_dict *x);
t_symbol *dict_dokey(t_dict *x, char *s, t_symbol *oldsym);
t_symbol *dict_key(t_dict *x, char *s);
void dict_bind(t_dict *x, t_pd *obj, t_symbol *s);
void dict_unbind(t_dict *x, t_pd *obj, t_symbol *s);
t_pd *dict_value(t_dict *x, t_symbol *s);
t_pd *dict_xvalue(t_dict *x, t_symbol *s);
int dict_forall(t_dict *x, t_symbol *s, t_dict_hook hook, void *hookarg);

#endif
