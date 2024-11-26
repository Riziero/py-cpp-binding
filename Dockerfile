FROM ubuntu:24.04
WORKDIR /usr/local/app


# About cmake, we might want to pull an archive from kitware
# to always get the same version. Like this we rely on newest.
RUN apt-get update && apt-get install -y \
    python3-dev	\
    cmake \
    pip \
    python3-venv \
    python3-pybind11 \
    uidmap \
    curl

# Set up venv the manual way
ENV VIRTUAL_ENV=/opt/venv
RUN python3 -m venv $VIRTUAL_ENV
ENV PATH="$VIRTUAL_ENV/bin:$PATH"

# Overkill using requirements.txt just for pytest...
COPY requirements.txt .
RUN pip install -r requirements.txt

# Copy in the source code
COPY . /src

# Setup an app user
RUN useradd sort

RUN mkdir -p /src
RUN chown  sort:sort /src
RUN chmod 755 /src

# Allow Python to mess inside/src/pytesting 
RUN chown  sort:sort /src/pytesting
RUN chmod 755 /src/pytesting


USER sort
WORKDIR /src

CMD ["bash", "-c", "/src/bootstrap.sh"]