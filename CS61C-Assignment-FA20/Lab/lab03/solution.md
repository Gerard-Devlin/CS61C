## ex1

```bash
java -jar tools/venus.jar
```

```bash
Usage: venus [-h] [-l libraries] [--def define] [-r RegisterWidth] [-t] [-tf TemplateFile] [-tp TemplatePattern] [-tb Radix] [-ti] [-tw] [-ts] [-tn NumberOfCommands] [-d] [-ur] [-n] [-it] [-ms MaxSteps] [-ahs] [-p Port] [-dm] [-cc] [--retToAllA] [-cf Coverage File] file simulatorArgs

  -h, --help                Prints help
  -l, --libs libraries      This is a list of library files you would like to assemble with the main file. Please separate them by a `;`.
  --def define              This is a list of define values which you want the assembler to have. Please note it must be in the format `key=value` and are separated by `;`.
  -r, --regwidth RegisterWidth
                            Sets register width (Currently only supporting 32 (default) and 64).
  -t, --trace               Trace the program given with the pattern given. If no pattern is given, it will use the default.
  -tf, --tracefile TemplateFile
                            Optional file/filepath to trace template to use. Only used if the trace argument is set.
  -tp, --tracepattern TemplatePattern
                            Optional pattern for the trace.
  -tb, --tracebase Radix    The radix which you want the trace to output. Default is 2 if omitted
  -ti, --traceInstFirst     Sets the tracer to put instructions first.       
  -tw, --tracePCWordAddr    Sets the pc output of the trace to be word addressed.
  -ts, --traceTwoStage      Sets the trace to be two stages.
  -tn, --traceTotalNumCommands NumberOfCommands
                            Sets the number of trace lines which will be printed (negative is ignored).
  -d, --dump                Dumps the instructions of the input program then quits.
  -ur, --unsetRegisters     All registers start as 0 when set.
  -n, --numberCycles        Prints out the total number of cycles.
  -it, --immutableText      When used, an error will be thrown when the code is modified.
  -ms, --maxsteps MaxSteps  Sets the max number of steps to allow (negative to not care).
  -ahs, --AllowHSAccess     Allows for load/store operations between the stack and heap. The default (without this flag) is to error on those acceses.    
  -p, --port Port           Port to serve on.
  -dm, --driveMount         Sets Venus to mount the directory specified by the 'file' to be a mountable drive.
  -cc, --callingConvention  Runs the calling convention checker.
  --retToAllA               If this flag is enabled, the calling convention checker will assume all `a` register can be used to return values. If this is not there, then it will assume only a0 will be returned.
  -cf, --coverageFile Coverage File
                            Specifies a file for the coverage output.        
  file                      This is the file/filepath you want to assemble   
  simulatorArgs             Args which are put into the simulated program.   

```

