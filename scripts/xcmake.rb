#!/usr/local/bin/ruby -w

require 'find'

topdir = ENV['SRCROOT']
pattern =/\w+\.\w{1,3}:\d+:\d+:\s(?:error|warning|note):\s.+/

`make 2> make.log`
output = File.read 'make.log'
messages = output.scan(pattern).to_a
messages.each do |m|
  file = m.match(/\w+.\w{1,2}/)[0]
  Find.find(topdir) do |path|
    if FileTest.directory?(path)
      if File.basename(path)[0] == ?.
        Find.prune
      else
        next
      end
    else
      puts "#{File.dirname pxath}/#{m}" if File.basename(path) == file
    end
  end
end

`rm make.log`
exit 1 unless messages.empty?
