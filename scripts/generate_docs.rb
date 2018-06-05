#
# generate_docs.rb - Generate Documentation using Doxygen
#
# Copyright (c) 2018, Aaron Sutton <aaronjsutton@icloud.com>
#

`which doxygen`
unless $? == 0
  raise "Could not run doxygen program."
  exit 1
end

Dir.chdir "#{__file__}/.."
system "doxygen"

`tar cvzf docs.tar.gz docs/`
exit $? unless $? == 0
`rm -r docs`
exit $? unless $? == 0
