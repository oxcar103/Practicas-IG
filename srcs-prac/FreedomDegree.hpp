#ifndef FREEDOM_DEGREE_HPP
#define FREEDOM_DEGREE_HPP


template<class T>
class FreedomDegree{
    private:
        bool rotating;
        T value;
        const T MIN_VALUE;
        const T MAX_VALUE;
        const T GROWTH;

    public:

        FreedomDegree(T t, const T min, const T max, const T rise = NULL, bool cyclicial = true)
            :MIN_VALUE(min), MAX_VALUE(max), GROWTH(rise)
        {
            rotating = cyclicial;
            value = t;
        }

        inline T get_value(){
            return value;
        }

        inline void increase(){
            if(value < MAX_VALUE){
                if(GROWTH == NULL){
                    value++;
                }
                else{
                    value += GROWTH;
                }
            }
            else if(rotating){
                value = MIN_VALUE;
            }
        }

        inline void decrease(){
            if(value > MIN_VALUE){
                if(GROWTH == NULL){
                    value--;
                }
                else{
                    value -= GROWTH;
                }
            }
            else if(rotating){
                value = MAX_VALUE;
            }
        }
};

#endif
