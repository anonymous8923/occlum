use super::*;

#[derive(Debug)]
pub struct DevZero;

impl File for DevZero {
    fn read(&self, _buf: &mut [u8]) -> Result<usize, Error> {
        for b in _buf.iter_mut() {
            *b = 0;
        }
        Ok(_buf.len())
    }

    fn read_at(&self, _offset: usize, _buf: &mut [u8]) -> Result<usize, Error> {
        self.read(_buf)
    }

    fn readv(&self, bufs: &mut [&mut [u8]]) -> Result<usize, Error> {
        let mut total_nbytes = 0;
        for buf in bufs {
            total_nbytes += self.read(buf)?;
        }
        Ok(total_nbytes)
    }

    fn write(&self, _buf: &[u8]) -> Result<usize, Error> {
        errno!(EINVAL, "device not support writes")
    }

    fn write_at(&self, _offset: usize, _buf: &[u8]) -> Result<usize, Error> {
        errno!(EINVAL, "device not support writes")
    }

    fn writev(&self, bufs: &[&[u8]]) -> Result<usize, Error> {
        errno!(EINVAL, "device not support writes")
    }

    fn seek(&self, pos: SeekFrom) -> Result<off_t, Error> {
        errno!(EINVAL, "device not support seeks")
    }

    fn metadata(&self) -> Result<Metadata, Error> {
        unimplemented!()
    }

    fn set_len(&self, len: u64) -> Result<(), Error> {
        errno!(EINVAL, "device not support resizing")
    }

    fn sync_all(&self) -> Result<(), Error> {
        Ok(())
    }

    fn sync_data(&self) -> Result<(), Error> {
        Ok(())
    }

    fn read_entry(&self) -> Result<String, Error> {
        errno!(ENOTDIR, "device is not a directory")
    }

    fn as_any(&self) -> &Any {
        self
    }
}
