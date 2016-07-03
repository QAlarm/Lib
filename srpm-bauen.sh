#! /bin/bash
tmp=/tmp/$(uuidgen)
spec=qalarm-lib.spec
version=$(cat Quellen/qalarmlib_global.h |grep LIBVERSION|cut -d \" -f 2)
name=qalarm-lib
name_version=${name}-${version}
sourcedir=$tmp/$name_version

mkdir -p $tmp/SPEC
mkdir $tmp/SOURCES
mkdir $tmp/SRPM
mkdir $sourcedir

sed -e "s|VERSION|$version|g" $spec >$tmp/SPEC/$spec
sed -i "s|SOURCE0|${name_version}.tar.gz|g" $tmp/SPEC/$spec

cp $tmp/SPEC/$spec $sourcedir
cp -r Quellen $sourcedir
cp Gemeinsam.pri LICENSE README.md Lib.pro $sourcedir


tar -czf $tmp/SOURCES/${name_version}.tar.gz -C $tmp --exclude=$spec $name_version

rpmbuild -bs --define "_topdir $tmp" $tmp/SPEC/$spec >/dev/null
mv $tmp/SRPMS/*.src.rpm .
rm -rf $tmp
