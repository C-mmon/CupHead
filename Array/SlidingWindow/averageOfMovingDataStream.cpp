
// Class to calculate the moving average of the last N numbers in a stream.
class MovingAverage {
    public:
        // Constructor initializes the circular buffer 'values_' with the given 'size' and resets the sum 'sum_' to 0.
        MovingAverage(int size) : size_(size), sum_(0), count_(0), values_(size, 0) {}
    
        double next(int value) {
            int index = count_ % size_;
          
            // Update sum: add the new value and subtract the value that is being replaced in the buffer
            sum_ += value - values_[index];
          
            // Assign the new value to the appropriate position in the circular buffer
            values_[index] = value;
          
            // Increase the count of the total number of values processed
            ++count_;
          
            // Calculate the average based on the minimum of 'count_' and 'size_'
            // This accounts for the case where fewer than 'size_' values have been processed
            return static_cast<double>(sum_) / std::min(count_, size_);
        }
    