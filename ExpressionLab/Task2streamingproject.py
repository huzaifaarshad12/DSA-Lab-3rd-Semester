from collections import deque
import heapq
import psutil

class VideoBuffer:
    def __init__(self, max_size):
        self.buffer = deque(maxlen=max_size)

    def add_frame(self, frame):
        self.buffer.append(frame)

    def get_frame(self):
        if self.buffer:
            return self.buffer.popleft()
        return None

def read_video_in_chunks(file_path, chunk_size):
    with open(file_path, 'rb') as video_file:
        while chunk := video_file.read(chunk_size):
            yield chunk

class FrameIndexer:
    def __init__(self):
        self.index = {}

    def add_frame(self, timestamp, frame_data):
        self.index[timestamp] = frame_data

    def get_frame(self, timestamp):
        return self.index.get(timestamp, None)

class PlaybackQueue:
    def __init__(self):
        self.queue = []

    def add_frame(self, priority, frame_data):
        heapq.heappush(self.queue, (priority, frame_data))

    def get_next_frame(self):
        if self.queue:
            return heapq.heappop(self.queue)[1]
        return None

class LazyVideoLoader:
    def __init__(self, file_path, chunk_size):
        self.file_path = file_path
        self.chunk_size = chunk_size
        self.reader = read_video_in_chunks(file_path, chunk_size)

    def load_next_chunk(self):
        try:
            return next(self.reader)
        except StopIteration:
            return None

def adjust_buffer_size(buffer, max_memory_usage):
    available_memory = psutil.virtual_memory().available
    if available_memory < max_memory_usage:
        buffer.buffer = deque(maxlen=max(buffer.buffer.maxlen // 2, 10))
    else:
        buffer.buffer = deque(maxlen=min(buffer.buffer.maxlen * 2, 1000))

# Integration of All Components
def video_stream(file_path, buffer_size, chunk_size, max_memory_usage):
    buffer = VideoBuffer(buffer_size)
    loader = LazyVideoLoader(file_path, chunk_size)

    while True:
        # Adjust buffer size dynamically
        adjust_buffer_size(buffer, max_memory_usage)

        # Fill buffer if not full
        while len(buffer.buffer) < buffer.buffer.maxlen:
            chunk = loader.load_next_chunk()
            if not chunk:
                break  # End of file
            buffer.add_frame(chunk)

        # Retrieve and "play" frame
        frame = buffer.get_frame()
        if frame:
            print("Playing frame...")  # Replace with actual frame display logic
        else:
            break  # No more frames

# Example Usage
if __name__ == "__main__":
    file_path = "D:\Documents\Semester3\DSA\09. Quick Sort.mp4"  # Replace with an actual video file path
    buffer_size = 50  # Initial buffer size
    chunk_size = 1024 * 1024  # 1 MB per chunk
    max_memory_usage = 500 * 1024 * 1024  # 500 MB max memory usage

    video_stream(file_path, buffer_size, chunk_size, max_memory_usage)
