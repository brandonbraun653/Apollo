#!/usr/bin/perl

#
# This script file creates a header file with the top level
# header files of PDK package.
#
use strict;
use warnings;
use Cwd;
use File::Find::Rule;
use File::Basename;

my $filecnt = 0;
my $counter = 0;
my $count_cpp_open = 0;
my $count_cpp_close = 0;
my $count_no_macro = 0;
my $count_noEnd_macro = 0;
my @file_list_noEndMacro;
my @file_list_noCppMacro;

my @component = ("csl" , "board" , "osal", "drv", "fs" , "utils", "transport");
my @depth = (1, 1, 1, 2, 2, 2, 3);

find(\&wanted);

sub wanted {
    unlink("$ARGV[0]/osal/test/cpptest/cpptest.h");
    for (my $i=0; $i < 7; $i++)
    {
        #print "$ARGV[0]/$component[$i]\n";
        #print "depth: $depth[$i]\n";
        my $rule = File::Find::Rule->new;
        my @headerFiles = File::Find::Rule->file()
                                       ->name( '*.h')
                                       ->maxdepth( $depth[$i] )
                                       ->in( "$ARGV[0]/$component[$i]" );

        my $fileName = "$ARGV[0]/osal/test/cpptest/cpptest.h";
        if (not defined $fileName)
        {
            print "ERROR: File Name not defined\n";
        } else {
            my $tempFile = "$ARGV[0]/osal/test/cpptest/cpptest.h";
            open my $temp, '>>', $tempFile or die "Could not create Header file $!\n";
            $counter = @headerFiles;
            for my $file (@headerFiles) {
                my ($extractString) = $file =~ m/packages\\*(.+)/;
                $extractString =~ s/\///;
                my $includeFile = "#include <$extractString>\n";
                if ($extractString =~ m/Settings/)
                {
                }
                elsif ($extractString =~ m/profiling_osal/)
                {}
                elsif ($extractString =~ m/csl_cacheAux/)
                {}
                elsif ($extractString =~ m/csl_chipAux/)
                {}
                elsif ($extractString =~ m/csl_pcie/)
                {}
                elsif ($extractString =~ m/csl_tmrAux/)
                {}
                elsif ($extractString =~ m/csl_semAux/)
                {}
                elsif ($extractString =~ m/csl_tmr/)
                {}
                elsif ($extractString =~ m/csl_pscAux/)
                {}
                elsif ($extractString =~ m/csl_ipcAux/)
                {}
                elsif ($extractString =~ m/csl_gpioAux/)
                {}
                elsif ($extractString =~ m/cslr_dmm_core/)
                {}
                elsif ($extractString =~ m/csl_msmcAux/)
                {}
                elsif ($extractString =~ m/cslr_dma4_ocp/)
                {}
                elsif ($extractString =~ m/nimu_icssEth/)
                {}
                elsif ($ARGV[1] =~ m/am65xx/)
                {
                    if ($extractString =~ m/cslr_mlb/)
                    {}
                    elsif ($extractString =~ m/csl_mlb/)
                    {}
                    elsif ($extractString =~ m/csl_idmaAux/)
                    {}
                    elsif ($extractString =~ m/csl_cgemAux/)
                    {}
                    elsif ($extractString =~ m/csl_rtc/)
                    {}
                    elsif ($extractString =~ m/csl_rtcAux/)
                    {}
                    elsif ($extractString =~ m/csl_serdes_10ge/)
                    {}
                    elsif ($extractString =~ m/csl_serdes_aif2/)
                    {}
                    elsif ($extractString =~ m/csl_serdes_dfe/)
                    {}
                    elsif ($extractString =~ m/csl_serdes_hyperlink/)
                    {}
                    elsif ($extractString =~ m/csl_serdes_iqn/)
                    {}
                    elsif ($extractString =~ m/csl_serdes_restore_default/)
                    {}
                    elsif ($extractString =~ m/csl_serdes_srio/)
                    {}
                    elsif ($extractString =~ m/csl_xmcAux/)
                    {}
                    elsif ($extractString =~ m/EventP/)
                    {}
                    else{
                    print $temp $includeFile;}
                }
                else{
                print $temp $includeFile;}
            }
        }
	}
}


