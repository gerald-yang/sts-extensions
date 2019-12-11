#include "defs.h"      /* From the crash source top-level directory */

void template_init(void);    /* constructor function */
void template_fini(void);    /* destructor function (optional) */

void cmd_template(void);     /* Declare the commands and their help data. */
char *help_template[];

static struct command_table_entry command_table[] = {
        { "template", cmd_template, help_template, 0},          /* One or more commands, */
        { NULL },                                     /* terminated by NULL, */
};


void __attribute__((constructor))
template_init(void) /* Register the command set. */
{ 
        register_extension(command_table);
}
 
/* 
 *  This function is called if the shared object is unloaded. 
 *  If desired, perform any cleanups here. 
 */
void __attribute__((destructor))
template_fini(void) { }


/* 
 *  Arguments are passed to the command functions in the global args[argcnt]
 *  array.  See getopt(3) for info on dash arguments.  Check out defs.h and
 *  other crash commands for usage of the myriad of utility routines available
 *  to accomplish what your task.
 */
void
cmd_template(void)
{
        int c;

        while ((c = getopt(argcnt, args, "")) != EOF) {
                switch(c)
                {
                default:
                        argerrs++;
                        break;
                }
        }

        if (argerrs)
                cmd_usage(pc->curcmd, SYNOPSIS);

        while (args[optind]) 
                fprintf(fp, "%s ", args[optind++]);

        fprintf(fp, "\n");
}

/* 
 *
 */
 
char *help_template[] = {
        "template",                        /* command name */
        "a template for reference",   /* short description */
        "arg ...",                     /* argument synopsis, or " " if none */
 
        "  This is a template command to echo argument list",
        "\nEXAMPLE",
        "  Echo arguments:\n",
        "    crash> template hello, world",
        "    hello, world",
        NULL
};


