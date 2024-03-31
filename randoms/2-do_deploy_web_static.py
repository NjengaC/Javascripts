#!/usr/bin/python3
"""
    Fabric script that distributes an archive to my web servers
"""
from fabric.api import *
from fabric.operations import run, put, sudo
import os

env.hosts = ['54.144.140.209', '34.202.233.3']
env.user = 'ubuntu'
env.key_filename = '~/.ssh/id_rsa'
env.warn_only = True


def do_deploy(archive_path):
    """
        using fabric to distribute archive
    """
    if not os.path.exists(archive_path):
        return False
    try:
        archive = os.path.basename(archive_path)
        path = "/data/web_static/releases/{}/".format(archive[:-4])
        put(archive, "/tmp/")

        run("sudo mkdir -p {}".format(path))
        run("sudo tar -xzf /tmp/{} -C {}"
            .format(archive, path))
        run("sudo rm /tmp/{}".format(archive))
        run("sudo mv -f {}/web_static/* {}"
            .format(path, path))
        run("sudo rm -rf {}/web_static".format(path))
        run("sudo rm -rf /data/web_static/current")
        run("sudo ln -sf {} /data/web_static/current"
            .format(path))
        print("New version deployed!")
        return True

    except Exception:
        return False
